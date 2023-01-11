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

bool USAttributeComponent::IsFullHealth() const
{
	return MaxHealth == Health;
}

float USAttributeComponent::GetHealth() const
{
	return Health;
}

float USAttributeComponent::GetHealthMax() const
{
	return MaxHealth;
}

bool USAttributeComponent::ApplyHealthChange(float Delta)
{
	float OldHealth = Health;

	Health = FMath::Clamp(Health + Delta, 0.0f, MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("Delta %f"), Delta);

	float ActualDelta = Health - OldHealth;
	OnHealthChanged.Broadcast(nullptr, this, Health, ActualDelta);

	return true;
}


