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

	UPROPERTY(EditAnywhere, Category = "Explosion_Particle")
	UParticleSystem* ExplosionParticle;

public:
	ASProjectileTeleport();
	
protected:
	void Explosion_TimeElapsed();
	void Teleport_Instigator();
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
