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
UCLASS()
class VALUESTORESYSTEM_API UValueStoreObject : public UObject, public IValueStoreInterface
{
	GENERATED_BODY()
	
public:

	// Holds the data
	FValueStoreStruct ValueStoreStruct;

	/* Stores 'Value' with 'Name' as key. Can be retrieved using GetStoredBoolean(Holder, Name).
	@param Holder	Object that holds the given value.
	@param Name		Name of this value.
	@param Value	Value to store.
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Value Store System")
	void SetStoredBoolean(const FName Name, const bool Value);
	virtual void SetStoredBoolean_Implementation(const FName Name, const bool Value) override;

	/* Retreive a boolean previously stored with 'Name' as key.
		@param Holder	Object that holds the given value.
		@param Name		Name of the value to retreive.
		@param Found	True if the stored value exists.
		@param Value	Value that was stored.
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure, Category = "Value Store System")
	void GetStoredBoolean(const FName Name, bool& Found, bool& Value);
	virtual void GetStoredBoolean_Implementation(const FName Name, bool& Found, bool& Value) override;

	/* Delete the boolean stored with `Name` as key.
		@param Holder	Object that holds the given value.
		@param Name		Name of the value to delete.
		@param Deleted	If the boolean existed.
	*/
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Value Store System")
	void DeleteStoredBoolean(const FName Name, bool& Deleted);
	virtual void DeleteStoredBoolean_Implementation(const FName Name, bool& Deleted) override;
};
