// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectile.h"
#include "SProjectileTeleport.generated.h"


class UParticleSystem;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASProjectileTeleport : public ASProjectile
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

protected:
	FTimerHandle TimerHandle_Explosion;
	FTimerHandle TimerHandle_Teleport;

public:
	ASProjectileTeleport();
	
protected:
	void Explosion_TimeElapsed();
	void Teleport_Instigator();

	// Base class using BlueprintNativeEvent, we must override the _Implementation not the Explode()
	virtual void Explode_Implementation() override;
};
