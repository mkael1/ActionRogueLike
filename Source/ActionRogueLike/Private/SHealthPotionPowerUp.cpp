// Fill out your copyright notice in the Description page of Project Settings.


#include "SHealthPotionPowerUp.h"
#include "Components/SphereComponent.h"
#include "SAttributeComponent.h"

ASHealthPotionPowerUp::ASHealthPotionPowerUp()
{
	SphereComp->SetSphereRadius(40.0f);
	SphereComp->SetSimulatePhysics(false);
	MeshComp->SetCollisionProfileName("NoCollision");

	CooldownSeconds = 10.0f;
}

void ASHealthPotionPowerUp::Interact_Implementation(APawn* InstigatorPawn)
{
	USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(InstigatorPawn->GetComponentByClass(USAttributeComponent::StaticClass()));
	if (ensure(AttributeComp))
	{
		if (AttributeComp->ApplyHealthChange(20.0f))
		{
			DisablePowerUp();
			GetWorldTimerManager().SetTimer(TimerHandle_HealthPotionCooldown, this, &ASHealthPotionPowerUp::Cooldown_TimeElapsed, CooldownSeconds);
		}
	}

}

void ASHealthPotionPowerUp::Cooldown_TimeElapsed()
{
	EnablePowerUp();
}

