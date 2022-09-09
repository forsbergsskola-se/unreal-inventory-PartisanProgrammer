// Fill out your copyright notice in the Description page of Project Settings.


#include "ExpandedAIController.h"
#include "CPP_PathFollowingComponent.h"


AExpandedAIController::AExpandedAIController()
{
	
}

AExpandedAIController::AExpandedAIController(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer.SetDefaultSubobjectClass<UCPP_PathFollowingComponent>(TEXT("PathFollowingComponent")))
{
	
}
