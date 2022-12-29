// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SBTService_CheckHealth.h"
#include "AIController.h"
#include "SAttributeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

void USBTService_CheckHealth::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UBlackboardComponent* BlackBoardComp = OwnerComp.GetBlackboardComponent();
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (ensure(AIController) && ensure(BlackBoardComp))
	{
		APawn* MyPawn = AIController->GetPawn();
		USAttributeComponent* AttributeComp = Cast<USAttributeComponent>(MyPawn->GetComponentByClass(USAttributeComponent::StaticClass()));
		if (ensure(AttributeComp))
		{
			if (AttributeComp->GetHealth() - AttributeComp->GetHealthMax() <= 0.99)
			{
				BlackBoardComp->SetValueAsBool("IsHiding", true);
			}
		}
	}
}
