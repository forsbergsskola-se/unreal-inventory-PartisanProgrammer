// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayEffectBase.h"

#include "AbilitySystemComponent.h"
#include "Components/AbilitySystemComponentBase.h"
#include "Net/UnrealNetwork.h"

UGameplayEffectBase::UGameplayEffectBase(){
}

void UGameplayEffectBase::Invoke(APawn* InteractorPawn, float Magnitude, float level){
	const FGameplayEffectModifierMagnitude NewMagnitudeModifier(Magnitude);
	Modifiers[0].ModifierMagnitude = NewMagnitudeModifier;
	
	UAbilitySystemComponentBase* AbilitySystemComponent = Cast<UAbilitySystemComponentBase>(InteractorPawn->GetComponentByClass(UAbilitySystemComponentBase::StaticClass()));
	if(AbilitySystemComponent == nullptr){
		UE_LOG(LogTemp, Warning, TEXT("AbilitySystemComponent is null"));
		return;
	}
	AbilitySystemComponent->ApplyGameplayEffectToSelf(this, level, AbilitySystemComponent->MakeEffectContext());
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Applying Effect: %s, Magnitude: %s, Target: %s"),
	
		*GetClass()->GetName(), ToCStr(Modifiers[0].ModifierMagnitude.GetValueForEditorDisplay().ToString()), *InteractorPawn->GetName()));
}

