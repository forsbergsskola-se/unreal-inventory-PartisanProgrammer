#pragma once
#include "ItemPDABase.h"
#include "Microsoft/AllowMicrosoftPlatformTypes.h"
#include "InventoryStructs.generated.h"
USTRUCT(BlueprintType, Blueprintable)
struct FItemStruct{
	GENERATED_BODY()
	FItemStruct(){};
	FItemStruct(UItemPDABase* itemPDA): Item(itemPDA), Quantity(1), Id(FGuid::NewGuid())	{}
	FItemStruct(UItemPDABase* itemPDA, int quantity):Item(itemPDA),Quantity(quantity), Id(FGuid::NewGuid()){}
	
	bool operator==(const FItemStruct &itemStruct) const
	{
		return this->Id == itemStruct.Id;
	}

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UItemPDABase* Item;
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	int Quantity;
	FGuid Id;
	// UPROPERTY(BlueprintReadWrite,EditAnywhere)
	// FGameplayTag ItemTag;

	bool IsValid() const;
};

