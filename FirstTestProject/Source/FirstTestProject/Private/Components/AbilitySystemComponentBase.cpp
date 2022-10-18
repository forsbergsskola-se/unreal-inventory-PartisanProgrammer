// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AbilitySystemComponentBase.h"

#include "GameplayAbilityBase.h"

void UAbilitySystemComponentBase::BeginPlay(){
	Super::BeginPlay();
	GrantAbilities();
}

bool UAbilitySystemComponentBase::GrantAbilities(){

	if (GrantedAbilities.IsEmpty()){
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
		                                 FString::Printf(TEXT("%s has no abilities to grant"), *GetOwner()->GetName()));
		return false;
	}

	for (const auto& Ability : GrantedAbilities){
		checkf(Ability,TEXT("%s has an invalid ability"), *GetOwner()->GetName());
		FGameplayAbilitySpec* FoundSpec = FindAbilitySpecFromClass(Ability);
		
		if(FoundSpec){
			if(FoundSpec->Ability->GetClass() == Ability){
				continue;
			}
		}
		
		FGameplayAbilitySpec AbilitySpec{Ability};
		GiveAbility(AbilitySpec);
	}

	return true;
}
