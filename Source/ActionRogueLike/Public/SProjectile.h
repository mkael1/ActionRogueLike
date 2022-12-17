// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectile.generated.h"


class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;
class UAudioComponent;

UCLASS()
class ACTIONROGUELIKE_API ASProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASProjectile();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USphereComponent* SphereComp;
	UPROPERTY(VisibleAnywhere)
		UProjectileMovementComponent* MovementComp;
	UPROPERTY(VisibleAnywhere)
		UParticleSystemComponent* EffectComp;
	UPROPERTY(VisibleAnywhere)
		UAudioComponent* AudioComp;

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		UParticleSystem* ImpactVFX;
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		USoundBase* ImpactSound;
	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		UCameraShakeBase* ImpactShakeEffect;

	UFUNCTION()
		virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void Explode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
