// Copyright Dream Seed LLC, 2022

#pragma once

#include "ValueStoreStruct.h"
#include "ValueStoreInterface.h"
#include "ValueStoreComponent.h"
#include "ValueStoreObject.h"

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
	static TScriptInterface<IValueStoreInterface> GetValueStore(UObject* Holder, const bool bCreateIfMissing);

public:

	/* Checks to see if Holder can be used to Set/Get/Delete Values stored with Value Store System.
	 * Always true for Actors.
	 * To Implement Value Store System on a UObject: Implement the IValueStoreHolderInterface on the object, and set up the interface functions to set and get a variable with IValueStoreInterface type.
		@param Holder	Object to check.
		@param Success	If the Holder can be used with Value Store System.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System", meta = (Keywords = "implements"))
	static void UsesValueStore(UObject* Holder, bool& Success);

	/* Get the Value Store Struct from the Holder. This contains all data stored on this actor with the Value Store System.
		@param Holder			Object that holds the Value Store data.
		@param IsValidHolder	If the Holder can be used with Value Store System.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void GetValueStoreStruct(UObject* Holder, bool& IsValidHolder, FValueStoreStruct& ValueStoreStruct);

	/* Set the Value Store data on the Holder. This will replace all data stored on this actor with the Value Store System.
		@param Holder	Object to hold Value Store data.
		@param Success	If the Holder could be used with Value Store System.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void SetValueStoreStruct(UObject* Holder, FValueStoreStruct ValueStoreStruct, bool& Success);

	/* Add the Value Store data on the Holder. This will merge the ValueStoreStruct with existing data stored on this actor with the Value Store System.
		@param Holder	Object to hold Value Store data.
		@param Success	If the Holder could be used with Value Store System.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void AddValueStoreStruct(UObject* Holder, FValueStoreStruct ValueStoreStruct, bool& Success);


	#pragma region Boolean

	/* Stores 'Value' with 'Name' as key. Can be retrieved using GetStoredBoolean(Holder, Name).
	    @param Holder	Object that holds the given value.
		@param Name		Name of this value.
		@param Value	Value to store.
		@param Success	If the Holder could handle this function.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void SetStoredBoolean(UObject* Holder, const FName Name, const bool Value, bool& Success);

	/* Retreive a boolean previously stored with 'Name' as key.
	    @param Holder	Object that holds the given value.
		@param Name		Name of the value to retreive.
		@param Found	True if the stored value exists.
		@param Value	Value that was stored.
		@param Success	If the Holder could handle this function.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Value Store System")
	static void GetStoredBoolean(UObject* Holder, const FName Name, bool& Found, bool& Value, bool& Success);

	/* Delete the boolean stored with `Name` as key.
		@param Holder	Object that holds the given value.
		@param Name		Name of the value to delete.
		@param Success	If the Holder could handle this function.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void DeleteStoredBoolean(UObject* Holder, const FName Name, bool& Success);

	#pragma endregion
	#pragma region Integer

	/* Stores 'Value' with 'Name' as key. Can be retrieved using GetStoredInteger(Holder, Name).
		@param Holder	Object that holds the given value.
		@param Name		Name of this value.
		@param Value	Value to store.
		@param Success	If the Holder could handle this function.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void SetStoredInteger(UObject* Holder, const FName Name, const int Value, bool& Success);

	/* Retreive a integer previously stored with 'Name' as key.
		@param Holder	Object that holds the given value.
		@param Name		Name of the value to retreive.
		@param Found	True if the stored value exists.
		@param Value	Value that was stored.
		@param Success	If the Holder could handle this function.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Value Store System")
	static void GetStoredInteger(UObject* Holder, const FName Name, bool& Found, bool& Value, bool& Success);

	/* Delete the integer stored with `Name` as key.
		@param Holder	Object that holds the given value.
		@param Name		Name of the value to delete.
		@param Success	If the Holder could handle this function.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store System")
	static void DeleteStoredInteger(UObject* Holder, const FName Name, bool& Success);

	#pragma endregion
};
