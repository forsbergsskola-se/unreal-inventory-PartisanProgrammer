// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "InventoryStructs.h"
#include "Engine/StaticMeshActor.h"
#include "ItemBase.generated.h"

UCLASS()
class INVENTORY_API AItemBase : public AStaticMeshActor, public IGameplayTagAssetInterface{
private:
	GENERATED_BODY()
	FGameplayTagContainer OwnedTags;
public:
	// Sets default values for this actor's properties
	AItemBase();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base", meta = (ExposeOnSpawn = true))
	FItemStruct ItemStruct;
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
UFUNCTION(BlueprintCallable, Category = "GameplayTags")
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	UFUNCTION(BlueprintCallable, Category = "GameplayTags")
	void SetOwnedGameplayTags(const FGameplayTagContainer& TagContainer);
	bool SetMesh() const;
};
