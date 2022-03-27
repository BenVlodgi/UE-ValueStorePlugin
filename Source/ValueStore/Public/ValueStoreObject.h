// Copyright Dream Seed LLC, 2022

#pragma once


#include "ValueStoreStruct.h"
#include "ValueStoreInterface.h"


#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValueStoreObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class VALUESTORESYSTEM_API UValueStoreObject : public UObject, public IValueStoreInterface
{
	GENERATED_BODY()
	
public:

	// Holds the data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Value Store System|Value Store Object")
	FValueStoreStruct ValueStoreStruct;

	virtual void SetStoredBoolean_Implementation(const FName Name, const bool Value) override;
	virtual void GetStoredBoolean_Implementation(const FName Name, bool& Found, bool& Value) override;
	virtual void DeleteStoredBoolean_Implementation(const FName Name, bool& Deleted) override;
};
