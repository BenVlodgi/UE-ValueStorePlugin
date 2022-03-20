// Fill out your copyright notice in the Description page of Project Settings.


#include "ValueStoreObject.h"

void UValueStoreObject::SetStoredBoolean(const FName Name, const bool Value)
{
	ValueStoreStruct.Booleans.Emplace(Name, Value);
}

void UValueStoreObject::GetStoredBoolean(const FName Name, bool& Found, bool& Value)
{
	bool* FindValue = ValueStoreStruct.Booleans.Find(Name);

	if (FindValue != nullptr)
	{
		Found = true;
		Value = *FindValue;
	}
	else
	{
		Found = false;
		Value = false;
	}
}

void UValueStoreObject::DeleteStoredBoolean(const FName Name, bool& Deleted)
{
	// Deleted will be true if the number of deleted entries is more than 0.
	Deleted = ValueStoreStruct.Booleans.Remove(Name) > 0;
}
