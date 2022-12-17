// Fill out your copyright notice in the Description page of Project Settings.


#include "SAttributeComponent.h"

// Sets default values for this component's properties
USAttributeComponent::USAttributeComponent()
{
	MaxHealth = 100;
	Health = 100;
}


bool USAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool USAttributeComponent::ApplyHealthChange(float Delta)
{
	// If max health and the delta is positive (healing) no health change
	if (Health == MaxHealth && Delta >= 0.0f)
	{
		return false;
	}

	Health += Delta;

	Health = FMath::Clamp(Health, 0.0f, MaxHealth);
	UE_LOG(LogTemp, Log, TEXT("NewHealth %f %"), Health / MaxHealth);
	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);

	return true;
}


