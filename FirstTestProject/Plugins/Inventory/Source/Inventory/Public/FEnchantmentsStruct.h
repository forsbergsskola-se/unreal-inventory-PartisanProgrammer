#pragma once
#include "NiagaraFunctionLibrary.h"
#include "FEnchantmentsStruct.generated.h"
USTRUCT(BlueprintType, Blueprintable)
struct FEnchantmentsStruct{
	GENERATED_BODY()
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsEnchanted;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UNiagaraSystem*EnchantmentEffect;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FColor Color;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int particleIntensityStatic;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float particleIntensityDynamic;;
};
