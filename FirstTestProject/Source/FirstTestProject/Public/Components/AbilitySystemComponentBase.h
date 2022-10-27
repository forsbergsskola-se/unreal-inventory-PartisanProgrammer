// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSetBase.h"
#include "GameplayAbilityBase.h"
#include "AbilitySystemComponentBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged,FGameplayAttribute,Attribute,float,NewValue);
UCLASS()
class FIRSTTESTPROJECT_API UAbilitySystemComponentBase : public UAbilitySystemComponent{
	GENERATED_BODY()
public:
	
	UAbilitySystemComponentBase();
	
	UPROPERTY(BlueprintAssignable,Category="Attribute")
	FOnHealthChanged OnHealthAttributeChanged;
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UAttributeSetBase>> GrantedAttributes;
	UPROPERTY(EditDefaultsOnly)
	UDataTable* AttributeDataTable;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<TSubclassOf<UGameplayAbilityBase>> GrantedAbilities;


	
    	
private:
	bool GrantAbilities();
	bool GrantAttributes();

	void OnHealthChanged(const FOnAttributeChangeData& Data) const;
};
