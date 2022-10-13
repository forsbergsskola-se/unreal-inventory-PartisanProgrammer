// Fill out your copyright notice in the Description page of Project Settings.


#include "AColorSphereBase.h"

#include "Kismet/KismetSystemLibrary.h"
#include "Net/UnrealNetwork.h"


void AAColorSphereBase::Interact_Implementation(AActor* HitActor,ACharacter* Interactor){
	if(!UKismetSystemLibrary::DoesImplementInterface(HitActor,UIInteract::StaticClass())){
		return;
	}
	IIInteract::Interact_Implementation(HitActor,Interactor);
}

// Sets default values
AAColorSphereBase::AAColorSphereBase(){
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
}

// Called when the game starts or when spawned
void AAColorSphereBase::BeginPlay(){
	Super::BeginPlay();
	Material = SphereComponent->GetMaterial(0);
	MID = SphereComponent->CreateDynamicMaterialInstance(0,Material);
}

void AAColorSphereBase::OnRepCurrentColorChanged() const{
	MID-> SetVectorParameterValue("Color", CurrentColor);
}

void AAColorSphereBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAColorSphereBase, CurrentColor);
}

// Called every frame
void AAColorSphereBase::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void AAColorSphereBase::RandomizeColor(){
		CurrentColor = FLinearColor(FMath::FRand(), FMath::FRand(), FMath::FRand(), 1.0f);
		OnRepCurrentColorChanged();
	
}

void AAColorSphereBase::ChangeColor(){
	//Random linearcolor
	
	
	// switch (CurrentColor){ case EColors::RED:
	// 	CurrentColor = COLOR_RED;
	// 	break;
	// case EColors::GREEN:
	// 	CurrentColor = EColors::GREEN;
	// 	break;
	// case EColors::BLUE:
	// 	CurrentColor = EColors::BLUE;
	// 	break;
	// case EColors::YELLOW:
	// 	CurrentColor = EColors::YELLOW;
	// 	break;
	// case EColors::PURPLE:
	// 	CurrentColor = EColors::PURPLE;
	// 	break;
	// default: ;
	// }

	OnRepCurrentColorChanged();

}

