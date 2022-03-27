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
UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VALUESTORESYSTEM_API UValueStoreComponent : public UActorComponent, public IValueStoreHolderInterface
{
	GENERATED_BODY()

public:

	UValueStoreComponent();

	/* Creates the Value Store Object for this component when initialized. 
	 * Otherwise it will be lazily created when data is first stored via this component.
	 */
	UPROPERTY(BlueprintReadWrite)
	bool bAutoGenerateValueStoreObject = false;

	UPROPERTY(BlueprintReadWrite)
	TScriptInterface<IValueStoreInterface> ValueStoreObjectReference;
	
	// IValueStoreHolderInterface implementations
	virtual TScriptInterface<IValueStoreInterface> GetValueStoreObject_Implementation() override;
	virtual void SetValueStoreObject_Implementation(const TScriptInterface<IValueStoreInterface>& ValueStore, bool& Success) override;
	
};
