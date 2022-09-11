// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Navigation/PathFollowingComponent.h"
#include "CPP_PathFollowingComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType)
class FIRSTTESTPROJECT_API UCPP_PathFollowingComponent : public UPathFollowingComponent
{
	
	
	
	GENERATED_BODY()
	

public:
	// Sets default values for this component's properti
	/**
	 * Creates spheres at every path point
	 */
	UPROPERTY(EditAnywhere, Category="Debug")
	bool debug;
	UPROPERTY(EditAnywhere, Category="Debug")
	FLinearColor debugColor;
	UCPP_PathFollowingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable, Category = "Debug")
	void DrawSphereAtTargetDestination(FLinearColor Color, float Radius, float LifeTime);

	UFUNCTION(BlueprintCallable, BlueprintPure,Category="Pathfinding")
	bool IsDestinationReachable(FVector endLocation);
};
