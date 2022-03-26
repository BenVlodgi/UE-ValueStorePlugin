// Copyright Dream Seed LLC, 2022

#pragma once

#include "ValueStoreInterface.h"
#include "ValueStoreHolderInterface.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ValueStoreComponent.generated.h"

/**
 Holds a ValueStore
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VALUESTORESYSTEM_API UValueStoreComponent : public UActorComponent, public IValueStoreHolderInterface
{
	GENERATED_BODY()

public:

	UValueStoreComponent();

	UPROPERTY(BlueprintReadWrite)
	TScriptInterface<IValueStoreInterface> ValueStoreObjectReference;
	
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Value Store System|Value Store Holder Interface")
	TScriptInterface<IValueStoreInterface> GetValueStoreObject();

	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Value Store System|Value Store Holder Interface")
	void SetValueStoreObject(const TScriptInterface<IValueStoreInterface>& ValueStore, bool& Success);
	
};
