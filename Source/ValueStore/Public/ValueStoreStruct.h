// Copyright Benjamin Thomas Blodgett

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValueStoreStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FValueStoreStruct
{
	GENERATED_BODY()
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, bool> Booleans;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, float> Floats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, int> Integers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, uint8> Bytes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, FVector> Vectors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, FRotator> Rotators;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, FTransform> Transforms;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, FName> Names;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, FString> Strings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, FText> Texts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, UObject*> Objects;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System")
	TMap<FName, TSubclassOf<UObject>> Classes;

	
};
