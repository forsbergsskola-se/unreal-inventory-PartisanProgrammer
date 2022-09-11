// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_PathFollowingComponent.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "AI/NavigationSystemBase.h"


// Sets default values for this component's properties
UCPP_PathFollowingComponent::UCPP_PathFollowingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UCPP_PathFollowingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCPP_PathFollowingComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if(debug)
		DrawSphereAtTargetDestination(debugColor, 50, 3);
}

void UCPP_PathFollowingComponent::DrawSphereAtTargetDestination(FLinearColor Color, float Radius, float LifeTime)
{
	if (!Path)
	{
		return;
	}
	TArray<FNavPathPoint> PathPoints = Path->GetPathPoints();
	//Draw line between each point
	for (int i = 0; i < PathPoints.Num() - 1; i++)
	{
		DrawDebugSphere(GetWorld(),PathPoints[i] , Radius, 12, Color.ToFColorSRGB(), false, LifeTime);
		DrawDebugLine(GetWorld(), PathPoints[i], PathPoints[i + 1], Color.ToFColorSRGB(), false, LifeTime);
		
	}

	
}

bool UCPP_PathFollowingComponent::IsDestinationReachable(FVector endLocation)
{
	UNavigationSystemV1* navSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	auto* pawn = Cast<AAIController>(GetOwner())->GetPawn();
	//Make a query using the pawn's location and the destination location
	FPathFindingQuery Query{GetOwner(),*MyNavData,pawn->GetActorLocation(), endLocation}; //FIX END
	return navSystem->TestPathSync(Query);
}


