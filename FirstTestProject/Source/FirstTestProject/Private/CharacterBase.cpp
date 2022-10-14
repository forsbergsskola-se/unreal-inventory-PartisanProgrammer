// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "IInteract.h"


// Sets default values
ACharacterBase::ACharacterBase(){
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent=CreateDefaultSubobject<UAbilitySystemComponentBase>(TEXT("AbilitySystemComponent"));
}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay(){
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterBase::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void ACharacterBase::PossessedBy(AController* NewController){
	Super::PossessedBy(NewController);

	if(AbilitySystemComponent){
		AbilitySystemComponent->InitAbilityActorInfo(this,this);
		
	}
	SetOwner(NewController);
}


// Called to bind functionality to input
void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACharacterBase::ServerInteract_Implementation(AActor* TargetActor, ACharacter* Interactor){
	IIInteract::Execute_Interact( this,TargetActor, Interactor ); //TODO: Check if this is correct
}

