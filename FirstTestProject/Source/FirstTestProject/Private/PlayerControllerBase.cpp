// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

#include "CharacterBase.h"


// Sets default values
APlayerControllerBase::APlayerControllerBase(){
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// void APlayerControllerBase::CallOnServer(TFunctionRef<void()>& FunctionToCall){
// 	if (HasAuthority()){
// 		FunctionToCall();
// 	}
// }

// Called when the game starts or when spawned
void APlayerControllerBase::BeginPlay(){
	Super::BeginPlay();
	
}

void APlayerControllerBase::AcknowledgePossession(APawn* P){ //The pawn is whoever is now being possessed
	Super::AcknowledgePossession(P);
	ACharacterBase* CharacterBase = Cast<ACharacterBase>(P);
	if(CharacterBase){
		CharacterBase-> AbilitySystemComponent->InitAbilityActorInfo(CharacterBase,CharacterBase);
	}
}

// Called every frame
void APlayerControllerBase::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

