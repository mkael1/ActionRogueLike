// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileTeleport.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"

ASProjectileTeleport::ASProjectileTeleport()
{
	PrimaryActorTick.bCanEverTick = true;
	MovementComp->InitialSpeed = 6500.0f;

}

void ASProjectileTeleport::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_Explosion, this, &ASProjectileTeleport::Explosion_TimeElapsed, 0.2f);
}

void ASProjectileTeleport::Explosion_TimeElapsed()
{
	MovementComp->StopMovementImmediately();
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactVFX, this->GetActorLocation());

	EffectComp->DeactivateSystem();
	SetActorEnableCollision(false);

	GetWorldTimerManager().SetTimer(TimerHandle_Teleport, this, &ASProjectileTeleport::Teleport_Instigator, 0.2f);
}

void ASProjectileTeleport::Teleport_Instigator()
{
	APawn* ProjectileInstigator = GetInstigator();
	if (ensure(ProjectileInstigator)) {
		ProjectileInstigator->TeleportTo(this->GetActorLocation(), ProjectileInstigator->GetActorRotation());
		Destroy();
	}
}

void ASProjectileTeleport::Explode_Implementation()
{
	MovementComp->StopMovementImmediately();
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactVFX, this->GetActorLocation());
	Teleport_Instigator();
}

