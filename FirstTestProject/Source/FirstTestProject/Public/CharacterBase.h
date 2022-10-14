// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/AbilitySystemComponentBase.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class FIRSTTESTPROJECT_API ACharacterBase : public ACharacter{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "AbilitySystem")
	UAbilitySystemComponentBase* AbilitySystemComponent;
	// Called every frame
	
	virtual void PossessedBy(AController* NewController) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Server")
	void ServerInteract(AActor* TargetActor, ACharacter* Interactor);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
