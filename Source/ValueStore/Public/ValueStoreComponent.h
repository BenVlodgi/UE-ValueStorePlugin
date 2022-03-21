// Copyright Benjamin Thomas Blodgett

#pragma once

#include "ValueStoreStruct.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ValueStoreComponent.generated.h"

/**
 Holds a ValueStoreObject
*/
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VALUESTORESYSTEM_API UValueStoreComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UValueStoreComponent();

	UPROPERTY(BlueprintReadWrite)
	UValueStoreObject ValueStoreObject;
	
};
