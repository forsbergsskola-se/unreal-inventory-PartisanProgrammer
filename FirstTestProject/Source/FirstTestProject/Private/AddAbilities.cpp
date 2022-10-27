// Fill out your copyright notice in the Description page of Project Settings.


#include "AddAbilities.h"

#include "AbilitySystemComponent.h"
#include "GameFeaturesSubsystem.h"
#include "Components/AbilitySystemComponentBase.h"
#include "Components/GameFrameworkComponentManager.h"

void UAddAbilities::OnGameFeatureActivating(FGameFeatureActivatingContext& Context){

	Super::OnGameFeatureActivating(Context);
	GameInstanceHandle = FWorldDelegates::OnStartGameInstance.AddUObject(this, &UAddAbilities::HandleGameInstanceStart);
}

void UAddAbilities::OnGameFeatureDeactivating(FGameFeatureDeactivatingContext& Context){
	Super::OnGameFeatureDeactivating(Context);
	FWorldDelegates::OnStartGameInstance.Remove(GameInstanceHandle);
}

void UAddAbilities::HandleGameInstanceStart(UGameInstance* GameInstance){
	UGameFrameworkComponentManager* ComponentManager = GameInstance->GetSubsystem<UGameFrameworkComponentManager>();

	for (int EntryIndex = 0; EntryIndex < Abilities.Num(); EntryIndex++){

		FGameFeatureAbilityEntry AbilityEntry = Abilities[EntryIndex];
		const auto ExtensionDelegate =
			UGameFrameworkComponentManager::FExtensionHandlerDelegate::CreateUObject(
				this, &UAddAbilities::HandleExtensionDelegate, EntryIndex);

		ExtensionHandler.Add(ComponentManager->AddExtensionHandler(AbilityEntry.ActorClass, ExtensionDelegate));
	}

}

void UAddAbilities::HandleExtensionDelegate(AActor* ActorClass, FName Name, int EntryIndex){
UAbilitySystemComponentBase* AbilitySystemComponent = ActorClass->FindComponentByClass<UAbilitySystemComponentBase>();

	const TSubclassOf<UGameplayAbilityBase> Ability = Abilities[EntryIndex].AbilityClass.LoadSynchronous();
	const FGameplayAbilitySpec AbilitySpec{Ability};
	AbilitySystemComponent->GiveAbility(AbilitySpec);
}
