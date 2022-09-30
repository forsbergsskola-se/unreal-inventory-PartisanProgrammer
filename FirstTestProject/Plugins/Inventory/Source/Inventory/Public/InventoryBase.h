// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryStructs.h"
#include "Components/ActorComponent.h"
#include "InventoryBase.generated.h"
//DECLARE_DYNAMIC_DELEGATE(FDelegateSignature);
#define PRINT(string) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red,string);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventoryChanged, FItemStruct, item);
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class INVENTORY_API UInventoryBase : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryBase();
	UPROPERTY(BlueprintAssignable, Category = "Inventory")
		FOnInventoryChanged OnInventoryChanged;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable,BlueprintPure)
	TArray<FItemStruct>& GetItems();
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(const FItemStruct& Item);
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	FItemStruct CreateItem(const FItemStruct& Item);
	
	UFUNCTION(BlueprintCallable,Category="Inventory")
	bool TryAddItem(const FItemStruct& Item);
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool TransferItem(UInventoryBase* ToInventory, const FItemStruct& Item);
	
	UPROPERTY(EditDefaultsOnly)
	bool IsDebugging;
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void Debug();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool DropItem(const FItemStruct& Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool DropAllItems();
	

private:
	TArray<FItemStruct> Items;
	
    bool TryIncreaseAmountInArray(const FItemStruct& Item);
	bool AddNewItem(const FItemStruct& NewItem);
};
