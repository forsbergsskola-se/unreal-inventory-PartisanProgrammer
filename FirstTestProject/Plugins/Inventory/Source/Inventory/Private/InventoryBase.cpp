// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryBase.h"

#include "ItemBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UInventoryBase::UInventoryBase(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryBase::BeginPlay(){
	Super::BeginPlay();

	// ...
}


// Called every frame
void UInventoryBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction){
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsDebugging){
		Debug();
	}
	// ...
}

TArray<FItemStruct>& UInventoryBase::GetItems(){
	return Items;
}

bool UInventoryBase::RemoveItem(const FItemStruct& Item){
	if (Items.Remove(Item) > 0){
		OnInventoryChanged.Broadcast(Item);
		return true;
	}
	return false;
}

bool UInventoryBase::AddNewItem(const FItemStruct& NewItem){
	if (!NewItem.IsValid()){
		return false;
	}

	Items.Add(NewItem);
	OnInventoryChanged.Broadcast(NewItem);

	return true;;
}

FItemStruct UInventoryBase::CreateItem(const FItemStruct& Item){
	return FItemStruct{Item.Item};
}

bool UInventoryBase::TryIncreaseAmountInArray(const FItemStruct& Item){
	for (FItemStruct& item : Items){
		if (item.Item == Item.Item){
			item.Quantity += Item.Quantity;
			OnInventoryChanged.Broadcast(Item);
			return true;
		}
	}
	return false;
}

bool UInventoryBase::TryAddItem(const FItemStruct& Item){
	if (!Item.IsValid()){
		return false;
	}
	if (!Item.Item->isStackable){
		AddNewItem(Item);
		return true;
	}
	if (Items.IsEmpty()){
		AddNewItem(Item);
		return true;
	}
	if (TryIncreaseAmountInArray(Item)){
		return true;
	}
	AddNewItem(Item);
	return true;
}

bool UInventoryBase::TransferItem(UInventoryBase* ToInventory, const FItemStruct& Item){
	if (ToInventory->TryAddItem(Item)){
		return RemoveItem(Item);
	}
	return false;
}

void UInventoryBase::Debug(){
	for (auto& item : Items){
		PRINT(item.Item->Name);
	}
}

// bool UInventoryBase::DropItem(const FItemStruct& Item){
// 	if (!Item.IsValid()){
// 		return false;
// 	}
// 	if (!Items.Contains(Item)){
// 		return false;
// 	}
// 	const auto Transform = GetOwner()->GetActorTransform();
// 	
// 	AItemBase* NewItem = GetWorld()->SpawnActorDeferred<AItemBase>(
// 		UItemPDABase::StaticClass(),
// 		Transform,
// 		nullptr,
// 		nullptr,
// 		ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
// 	NewItem->ItemStruct = Item;
// 	//NewItem->FinishSpawning(Transform);
// 	UGameplayStatics::FinishSpawningActor(NewItem, Transform);
// 	
// 	RemoveItem(Item);
// 	return true;
// }
//
// bool UInventoryBase::DropAllItems(){
// 	DropItem(Items[0]);
// 	return true;
// }
