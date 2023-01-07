// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTTask_Heal.h"

#include "AIController.h"
#include "SAttributeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USBTTask_Heal::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* MyController = OwnerComp.GetAIOwner();
	if (ensure(MyController))
	{
		APawn* MyPawn = MyController->GetPawn();
		if (MyPawn == nullptr)
		{
			return EBTNodeResult::Failed;
		}
		USAttributeComponent* AttributeComponent = Cast<USAttributeComponent>(MyPawn->GetComponentByClass(USAttributeComponent::StaticClass()));

		if (ensure(AttributeComponent))
		{
			AttributeComponent->ApplyHealthChange(AttributeComponent->GetHealthMax());
			UBlackboardComponent* BlackboardComponent =  OwnerComp.GetBlackboardComponent();
			BlackboardComponent->SetValueAsBool("IsHiding", false);
			BlackboardComponent->SetValueAsBool("HealOnCooldown", true);
			return EBTNodeResult::Succeeded;
		}
		return EBTNodeResult::Failed;
	}
	return EBTNodeResult::Failed;
}