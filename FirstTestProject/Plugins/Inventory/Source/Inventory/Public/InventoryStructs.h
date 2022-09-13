#pragma once
#include "ItemPDABase.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"
#include "InventoryStructs.generated.h"
USTRUCT(BlueprintType, Blueprintable)
struct FItemStruct{
	GENERATED_BODY()
	bool operator==(const FItemStruct &itemStruct) const
	{
		return this->Item == itemStruct.Item;
	}

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemPDABase* Item;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int Quantity;
	// UPROPERTY(BlueprintReadWrite,EditAnywhere)
	// FGameplayTag ItemTag;
};

