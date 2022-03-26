// Copyright Dream Seed LLC, 2022

#pragma once

#include "ValueStoreInterface.h"

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
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Value Store System|Value Store Holder Interface")
	TScriptInterface<IValueStoreInterface> GetValueStoreObject();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Value Store System|Value Store Holder Interface")
	void SetValueStoreObject(const TScriptInterface<IValueStoreInterface>& ValueStore, bool &Success);

};