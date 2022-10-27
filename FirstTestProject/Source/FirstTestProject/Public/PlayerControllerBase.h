// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerControllerBase.generated.h"

UCLASS()
class FIRSTTESTPROJECT_API APlayerControllerBase : public APlayerController{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlayerControllerBase();
	
	//Ufunction CallOnServer is used to call a function on the server with a TFunction as input
	
	//void CallOnServerInternal(TFunction<void()> FunctionToCall);
	
	
	
	
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void AcknowledgePossession(APawn* P) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
