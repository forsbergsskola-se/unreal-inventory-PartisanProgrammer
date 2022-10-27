// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "UObject/Object.h"
#include "GameplayEffectBase.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTTESTPROJECT_API UGameplayEffectBase : public UGameplayEffect{
	GENERATED_BODY()

	public	:
	UGameplayEffectBase();

	UFUNCTION(BlueprintCallable, Category = "GameplayEffect")
	void Invoke(APawn* InteractorPawn,float Magnitude,float level);
};
