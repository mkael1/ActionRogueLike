// Fill out your copyright notice in the Description page of Project Settings.

#include "PhysicsEngine/RadialForceComponent.h"
#include "SProjectileBlackhole.h"

// Sets default values
ASProjectileBlackhole::ASProjectileBlackhole()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RadialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialForceComp");
	RadialForceComp->SetupAttachment(RootComponent);
	RadialForceComp->ForceStrength = -2500000.0f;
	RadialForceComp->Radius = 2000.0f;
}

// Called when the game starts or when spawned
void ASProjectileBlackhole::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASProjectileBlackhole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

