// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SPowerUp.generated.h"

class UMeshComponent;
class USphereComponent;

UCLASS()
class ACTIONROGUELIKE_API ASPowerUp : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere)
	UMeshComponent* MeshComp;
	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComp;
	
public:	
	// Sets default values for this actor's properties
	ASPowerUp();

	void Interact_Implementation(APawn* InstigatorPawn);

protected:

	void EnablePowerUp();
	void DisablePowerUp();
	UPROPERTY(VisibleAnywhere)
		bool IsOnCooldown = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
		float CooldownSeconds = 5.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
