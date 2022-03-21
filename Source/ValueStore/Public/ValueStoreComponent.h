// Copyright Dream Seed LLC, 2022

#pragma once

#include "ValueStoreInterface.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ValueStoreComponent.generated.h"

/**
 Holds a ValueStore
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VALUESTORESYSTEM_API UValueStoreComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UValueStoreComponent();

	UPROPERTY(BlueprintReadWrite)
	TScriptInterface<IValueStoreInterface> ValueStore;
	
};
