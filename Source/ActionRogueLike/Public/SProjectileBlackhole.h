// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectile.h"
#include "SProjectileBlackhole.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASProjectileBlackhole : public ASProjectile
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ASProjectileBlackhole();

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
