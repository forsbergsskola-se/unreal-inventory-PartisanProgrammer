#pragma once
#include "ItemPDABase.h"
#include "InventoryStructs.generated.h"
USTRUCT(BlueprintType, Blueprintable)
struct FItemStruct{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemPDABase* Item;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int Quantity;
	// UPROPERTY(BlueprintReadWrite,EditAnywhere)
	// FGameplayTag ItemTag;
};

