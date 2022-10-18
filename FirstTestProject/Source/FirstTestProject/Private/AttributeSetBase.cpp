// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBase.h"

#include "Net/UnrealNetwork.h"

UAttributeSetBase::UAttributeSetBase(){
}

void UAttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase,Health,COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase,Stamina,COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBase,AttackPower,COND_None, REPNOTIFY_Always);
}

void UAttributeSetBase::OnRep_Health(const FGameplayAttributeData& OldHealth){
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, Health, OldHealth);
}

void UAttributeSetBase::OnRep_Stamina(const FGameplayAttributeData& OldStamina){
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, Stamina,OldStamina);
}

void UAttributeSetBase::OnRep_AttackPower(const FGameplayAttributeData& OldAttackPower){
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBase, AttackPower,OldAttackPower);
}
