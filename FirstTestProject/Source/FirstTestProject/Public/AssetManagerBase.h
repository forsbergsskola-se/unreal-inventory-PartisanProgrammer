﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"

#include "AssetManagerBase.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTTESTPROJECT_API UAssetManagerBase : public UAssetManager{
	GENERATED_BODY()
	virtual void StartInitialLoading() override;
};
