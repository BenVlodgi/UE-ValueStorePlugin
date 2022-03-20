// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ValueStoreObject.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValueStoreHolderInterface.generated.h"


UINTERFACE(BlueprintType)
class VALUESTORESYSTEM_API UValueStoreHolderInterface : public UInterface
{
	GENERATED_BODY()

};

class VALUESTORESYSTEM_API IValueStoreHolderInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Value Store Interface")
	UValueStoreObject* GetValueStoreObject();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Value Store Interface")
	void SetValueStoreObject(UValueStoreObject* ValueStoreObject, bool &Success);

};