// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "FEnchantmentsStruct.h"
#include "GameplayTagContainer.h"
#include "ItemPDABase.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class INVENTORY_API UItemPDABase : public UPrimaryDataAsset
{
	GENERATED_BODY()
	bool operator==(const UItemPDABase& Other) const
	{
		return this->Id == Other.Id;
	}

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
		FString Name;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
		UStaticMesh* Mesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	UTexture2D* Icon;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	bool  isStackable;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	USoundBase* PickupSound;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Item")
	USoundBase * DropSound;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enchantment")
	TArray<FEnchantmentsStruct> Enchantments;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Generic")
		TMap<FString,float> Atri_Floats;


	FGuid Id;
	

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	bool Use(APawn* Pawn);
	UFUNCTION(BlueprintCallable, Category = "GameplayTags")
	void SetOwnedGameplayTags(const FGameplayTagContainer& TagContainer);

private:
	FGameplayTagContainer OwnedTags;
};
