// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerUp.h"
#include "SHealthPotionPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASHealthPotionPowerUp : public ASPowerUp
{
	GENERATED_BODY()
	
public:
	ASHealthPotionPowerUp();

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

protected:
	FTimerHandle TimerHandle_HealthPotionCooldown;

	void Cooldown_TimeElapsed();
};
