// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;
class USAttributeComponent;
class UAnimMontage;
class UParticleSystem;


UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;
	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	UPROPERTY(EditAnywhere, Category = "BlackholeAttack")
	TSubclassOf<AActor> BlackholeClass;
	UPROPERTY(EditAnywhere, Category = "BlackholeAttack")
	UAnimMontage* BlackholeAnim;

	UPROPERTY(EditAnywhere, Category = "Teleport")
		TSubclassOf<AActor> TeleportClass;
	UPROPERTY(EditAnywhere, Category = "Teleport")
		UAnimMontage* TeleportAnim;

	UPROPERTY(EditAnywhere, Category = "Attack")
		UParticleSystem* ParticleMuzzle;

	FTimerHandle TimerHandle_PrimaryAttack;
	FTimerHandle TimerHandle_BlackholeAttack;
	FTimerHandle TimerHandle_Teleport;


public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	UPROPERTY(VisibleAnywhere);
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere);
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere);
	USInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components");
	USAttributeComponent* AttributeComp;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Jump();

	void PrimaryAttack();
	void PrimaryAttack_TimeElapsed();

	void BlackholeAttack();
	void BlackholeAttack_TimeElapsed();

	void Teleport();
	void Teleport_TimeElapsed();

	void SpawnProjectile(TSubclassOf<AActor> ProjectileClass);

	FRotator GetCameraDirection();

	void PrimaryInteract();

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta);

	virtual void PostInitializeComponents();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
