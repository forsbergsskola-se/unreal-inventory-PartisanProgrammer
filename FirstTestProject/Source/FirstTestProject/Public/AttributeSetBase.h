// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AttributeSetBase.generated.h"

//Helpful Macros From UAttributeSet.h
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class FIRSTTESTPROJECT_API UAttributeSetBase : public UAttributeSet{
	GENERATED_BODY()
	
public:
	
	UAttributeSetBase();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; //Replication
	
#pragma region Health
	UPROPERTY(BlueprintReadOnly, Category="Attributes", ReplicatedUsing = OnRep_Health) //Becomes replicated when using OnRep_Health
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Health);

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth); //Replication 
#pragma endregion

#pragma region Stamina
	UPROPERTY(BlueprintReadOnly,Category="Attributes", ReplicatedUsing=OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UAttributeSetBase, Stamina);

	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);
#pragma endregion

#pragma region AttackPower
	UPROPERTY(BlueprintReadOnly,Category="Attributes",ReplicatedUsing = OnRep_AttackPower)
	FGameplayAttributeData AttackPower;

	UFUNCTION()
	virtual void OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower);

#pragma endregion
	
	
};
