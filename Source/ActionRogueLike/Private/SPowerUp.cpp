// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ASPowerUp::ASPowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetupAttachment(RootComponent);

}

void ASPowerUp::Interact_Implementation(APawn* InstigatorPawn)
{
	// logic in derived classes
}

void ASPowerUp::EnablePowerUp()
{
	IsOnCooldown = false;
	SphereComp->SetCollisionProfileName("OverlapAllDynamic");
	RootComponent->SetVisibility(true);
}

void ASPowerUp::DisablePowerUp()
{
	IsOnCooldown = true;
	SphereComp->SetCollisionProfileName("NoCollision");
	RootComponent->SetVisibility(false);
}

// Called when the game starts or when spawned
void ASPowerUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASPowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

