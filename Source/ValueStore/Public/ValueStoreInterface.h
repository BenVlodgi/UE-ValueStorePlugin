// Copyright Benjamin Thomas Blodgett

#pragma once

#include "ValueStoreStruct.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ValueStoreInterface.generated.h"


UINTERFACE(BlueprintType)
class VALUESTORESYSTEM_API UValueStoreInterface : public UInterface
{
	GENERATED_BODY()
	
};

class VALUESTORESYSTEM_API IValueStoreInterface
{
	GENERATED_BODY()

public:
	
	/* Stores 'Value' with 'Name' as key. Can be retrieved using GetStoredBoolean(Holder, Name).
		@param Name		Name of this value.
		@param Value	Value to store.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store Interface")
	void SetStoredBoolean(const FName Name, const bool Value);

	/* Retreive a boolean previously stored with 'Name' as key.
		@param Name		Name of the value to retreive.
		@param Found	True if the stored value exists.
		@param Value	Value that was stored.
	*/
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Value Store Interface")
	void GetStoredBoolean(const FName Name, bool& Found, bool& Value);

	/* Delete the boolean stored with `Name` as key.
		@param Name		Name of the value to delete.
		@param Deleted	If the boolean existed.
	*/
	UFUNCTION(BlueprintCallable, Category = "Value Store Interface")
	void DeleteStoredBoolean(const FName Name, bool& Deleted);

};
