// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilityInputIDBase.h"
#include "Abilities/GameplayAbility.h"
#include "GameplayAbilityBase.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTTESTPROJECT_API UGameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()
public:

	UGameplayAbilityBase();

	//Abilities with this set will automatically activate when the input is pressed
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	EAbilityInputIDBase AbilityInputID = EAbilityInputIDBase::None;
};
