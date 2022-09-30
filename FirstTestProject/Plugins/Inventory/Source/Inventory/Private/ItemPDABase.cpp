// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemPDABase.h"

bool UItemPDABase::Use_Implementation(APawn* Pawn){
	return false;
}

void UItemPDABase::SetOwnedGameplayTags(const FGameplayTagContainer& TagContainer){
	OwnedTags = TagContainer;
}
