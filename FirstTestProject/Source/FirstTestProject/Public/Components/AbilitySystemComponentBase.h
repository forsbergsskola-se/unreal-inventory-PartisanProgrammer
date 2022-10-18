// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayAbilityBase.h"
#include "AbilitySystemComponentBase.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTTESTPROJECT_API UAbilitySystemComponentBase : public UAbilitySystemComponent{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbilityBase>> GrantedAbilities;
	
public:
	
private:
	bool GrantAbilities();
};
