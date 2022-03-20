// Copyright Dream Seed LLC, 2022

#pragma once

#include "ValueStoreStruct.h"
#include "ValueStoreInterface.h"
#include "ValueStoreComponent.h"

#include "Containers/Map.h"
#include "UObject/UnrealType.h"
#include "UObject/Field.h"


#include "Kismet/BlueprintFunctionLibrary.h"
#include "ValueStoreLibrary.generated.h"

UCLASS()
class UValueStoreLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static UValueStoreObject* UValueStoreLibrary::GetValueStoreObject(UObject* Holder, const bool bCreateIfMissing);


public:
	/* Stores 'Value' with 'Name' as key. Can be retrieved using GetStoredBoolean(Holder, Name).
	    @param Holder	Object that holds the given value.
		@param Name		Name of this value.
		@param Value	Value to store.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void SetStoredBoolean(UObject* Holder, const FName Name, const bool Value, bool& Success);

	/* Retreive a boolean previously stored with 'Name' as key.
	    @param Holder	Object that holds the given value.
		@param Name		Name of the value to retreive.
		@param Found	True if the stored value exists.
		@param Value	Value that was stored.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Value Store System")
	static void GetStoredBoolean(UObject* Holder, const FName Name, bool& Found, bool& Value, bool& Success);

	/* Delete the boolean stored with `Name` as key.
		@param Holder	Object that holds the given value.
		@param Name		Name of the value to delete
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void DeleteStoredBoolean(UObject* Holder, const FName Name, bool& Success);



};
