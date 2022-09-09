// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ExpandedAIController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FIRSTTESTPROJECT_API AExpandedAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AExpandedAIController();
	AExpandedAIController(const FObjectInitializer& ObjectInitializer);
};
