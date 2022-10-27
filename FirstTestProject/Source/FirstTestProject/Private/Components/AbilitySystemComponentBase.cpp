// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/AbilitySystemComponentBase.h"

#include "GameplayAbilityBase.h"

UAbilitySystemComponentBase::UAbilitySystemComponentBase(){
}

void UAbilitySystemComponentBase::BeginPlay(){
	Super::BeginPlay();

	GrantAbilities();
	GrantAttributes();
	GetGameplayAttributeValueChangeDelegate(UAttributeSetBase::GetHealthAttribute()).AddUObject(this, &UAbilitySystemComponentBase::OnHealthChanged);;
}

bool UAbilitySystemComponentBase::GrantAbilities(){

	if (GrantedAbilities.IsEmpty()){
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
		FString::Printf(TEXT("%s has no abilities to grant"), *GetOwner()->GetName()));
		return false;
	}

	for (const auto& Ability : GrantedAbilities){
		checkf(Ability, TEXT("%s has an invalid ability"), *GetOwner()->GetName());
		FGameplayAbilitySpec* FoundSpec = FindAbilitySpecFromClass(Ability);

		if (FoundSpec){
			if (FoundSpec->Ability->GetClass() == Ability){
				continue;
			}
		}

		FGameplayAbilitySpec AbilitySpec{Ability};
		GiveAbility(AbilitySpec);
	}

	return true;
}

bool UAbilitySystemComponentBase::GrantAttributes(){
	if (GrantedAttributes.IsEmpty()){
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red,
		FString::Printf(TEXT("%s has no attributes to grant"), *GetOwner()->GetName()));
		return false;
	}
	for (auto Attribute : GrantedAttributes){
		if (GetAttributeSubobject(Attribute) != nullptr) continue;
		auto* NewAttributeSet = NewObject<UAttributeSet>(GetOwner(), Attribute);
		NewAttributeSet->InitFromMetaDataTable(AttributeDataTable);
		AddAttributeSetSubobject(NewAttributeSet);
	}

	return true;
}

void UAbilitySystemComponentBase::OnHealthChanged(const FOnAttributeChangeData& Data) const{
	OnHealthAttributeChanged.Broadcast(Data.Attribute,Data.NewValue);
}
