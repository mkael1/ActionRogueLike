// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileTeleport.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"

ASProjectileTeleport::ASProjectileTeleport()
{
	PrimaryActorTick.bCanEverTick = true;
	MovementComp->InitialSpeed = 6500.0f;

}

void ASProjectileTeleport::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_Explosion, this, &ASProjectileTeleport::Explosion_TimeElapsed, 0.2f);
	SphereComp->OnComponentHit.AddDynamic(this, &ASProjectileTeleport::OnHit);
}

void ASProjectileTeleport::Explosion_TimeElapsed()
{
	MovementComp->StopMovementImmediately();
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, this->GetActorLocation());
	GetWorldTimerManager().SetTimer(TimerHandle_Teleport, this, &ASProjectileTeleport::Teleport_Instigator, 0.2f);
}

void ASProjectileTeleport::Teleport_Instigator()
{
	APawn* ProjectileInstigator = GetInstigator();
	ProjectileInstigator->TeleportTo(this->GetActorLocation(), ProjectileInstigator->GetActorRotation());
	Destroy();
}

void ASProjectileTeleport::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	MovementComp->StopMovementImmediately();
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, this->GetActorLocation());
	Teleport_Instigator();
}

