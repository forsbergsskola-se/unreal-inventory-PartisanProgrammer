// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInteract.h"
#include "GameFramework/Actor.h"
#include "AColorSphereBase.generated.h"
UENUM(BlueprintType)
enum class EColors:uint8{
	RED,
	GREEN,
	BLUE,
	YELLOW,
	PURPLE,
};
UCLASS()
class FIRSTTESTPROJECT_API AAColorSphereBase : public AActor, public IIInteract{
public:
	virtual void Interact_Implementation(ACharacter* Interactor) override;

private:
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	
	UMaterialInstanceDynamic* MID;
	UMaterialInterface* Material;
	AAColorSphereBase();
	
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(ReplicatedUsing=OnRepCurrentColorChanged)
	FLinearColor CurrentColor;
	UFUNCTION()
	void OnRepCurrentColorChanged() const;
	UPROPERTY(EditDefaultsOnly, Category = "Color")
    UStaticMeshComponent* SphereComponent;
	UPROPERTY(EditDefaultsOnly, Category = "Color")
	TMap<EColors,UMaterialInterface*> MaterialMap;

private:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "Color")
	void RandomizeColor();
	UFUNCTION(BlueprintCallable, Category = "Color")
	void ChangeColor();

};
