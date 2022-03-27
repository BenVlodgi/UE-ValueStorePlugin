// Copyright Dream Seed LLC, 2022

#include "ValueStoreLibrary.h"
#include "ValueStoreSystem.h"

UValueStoreLibrary::UValueStoreLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

UObject* UValueStoreLibrary::GetValueStoreObject(UObject* Holder, const bool bCreateIfMissing)
{
	if (!IsValid(Holder))
	{
		UE_LOG(LogTemp, Warning, TEXT("Holder is not Valid."));
		return NULL;
	}

	// If the holder implements IValueStoreInterface, then return it. 
	if (Holder->GetClass()->ImplementsInterface(UValueStoreInterface::StaticClass()))
	{
		return Holder;
	}
	
	if (Holder->GetClass()->ImplementsInterface(UValueStoreHolderInterface::StaticClass()))
	{
		// The holder implements IValueStoreHolderInterface, then get the IValueStoreInterface object from it. 
		UObject* ValueStoreInterfaceObject = IValueStoreHolderInterface::Execute_GetValueStoreObject(Holder).GetObject();

		if (IsValid(ValueStoreInterfaceObject))
		{
			return ValueStoreInterfaceObject;
		}
		else if (bCreateIfMissing)
		{
			// Generate new Generic ValueStoreObject
			ValueStoreInterfaceObject = NewObject<UValueStoreObject>(Holder, FName("ValueStoreObject"));

			// Set the ValueStoreObject
			bool Success;
			IValueStoreHolderInterface::Execute_SetValueStoreObject(Holder, ValueStoreInterfaceObject, Success);

			if (!Success)
			{
				UE_LOG(LogTemp, Warning, TEXT("Holder (%s) did not report setting the Value Store Object correctly, check its ValueStoreHolderInterface and ensure it is implemented correctly and returns Success = true."), *Holder->GetName());
			}

			UObject* ValueStoreInterfaceObject_Set = IValueStoreHolderInterface::Execute_GetValueStoreObject(Holder).GetObject();
			if (ValueStoreInterfaceObject != ValueStoreInterfaceObject_Set)
			{
				UE_LOG(LogTemp, Warning, TEXT("Holder (%s) did not set the Value Store Object correctly, check its ValueStoreHolderInterface and ensure it is implemented correctly."), *Holder->GetName());

				// Return the one that is actually stored now on the object
				return ValueStoreInterfaceObject_Set;
			}

			return ValueStoreInterfaceObject;
		}
	}
	else
	{
		// If the holder does not implement ValueStoreHolderInterface, then check if it has a component that implements one of the interfaces
		AActor* HolderAsActor = Cast<AActor>(Holder);
		if(HolderAsActor)
		{
			// Get Component from Actor that implements ValueStoreInterface
			TArray<UActorComponent*> InterfaceComponents = HolderAsActor->GetComponentsByInterface(UValueStoreInterface::StaticClass());
			if (InterfaceComponents.Num() > 0)
			{
				if (InterfaceComponents.Num() > 1)
				{
					UE_LOG(LogTemp, Warning, TEXT("Holder (%s) is an Actor, and has more than one component that implements ValueStoreHolderInterface. This is not recommended, we can't know which one to use, so we use the first one in the list."), *Holder->GetName());
				}
				return InterfaceComponents[0];
			}
			
			// Get Component from Actor that implements ValueStoreHolderInterface
			InterfaceComponents = HolderAsActor->GetComponentsByInterface(UValueStoreHolderInterface::StaticClass());
			if (InterfaceComponents.Num() > 0)
			{
				return GetValueStoreObject(InterfaceComponents[0], bCreateIfMissing);
			}
			else if(bCreateIfMissing)
			{
				UActorComponent* Component = NewObject<UValueStoreComponent>(HolderAsActor);
				Component->RegisterComponent();

				return GetValueStoreObject(Component, bCreateIfMissing);
			}
			else
			{
				// Holder is an Actor, doesn't have a component with one of our interfaces. Also CreateIfMissing is false, so we shouldn't make one. 
				// TODO: Remove this log, it is just for debugging
				UE_LOG(LogTemp, Display, TEXT("Holder (%s) is an Actor, doesn't have a component with one of our interfaces. Also CreateIfMissing is false, so we shouldn't make one."), *Holder->GetName());
				return NULL;
			}
		}
		else
		{
			// This Holder, does not implement either interface, and is not an actor, there is no way we can get a ValueStore from it.
			UE_LOG(LogTemp, Warning, TEXT("To use this object (%s) as a Value Store, Implement the ValueStoreHolderInterface."), *Holder->GetName());
			return NULL;
		}
	}

	return NULL;
}


void UValueStoreLibrary::ImplementsValueStore(UObject* Holder, bool& Success)
{
	// TODO: Implement
	Success = true;
}

void UValueStoreLibrary::GetValueStoreStruct(UObject* Holder, bool& IsValidHolder, FValueStoreStruct& ValueStoreStruct)
{
	// TODO: Implement
	IsValidHolder = true;
}

void UValueStoreLibrary::SetValueStoreStruct(UObject* Holder, FValueStoreStruct ValueStoreStruct, bool& Success)
{
	// TODO: Implement
	Success = true;
}

void UValueStoreLibrary::AddValueStoreStruct(UObject* Holder, FValueStoreStruct ValueStoreStruct, bool& Success)
{
	// TODO: Implement
	Success = true;
}

#pragma region Boolean
void UValueStoreLibrary::SetStoredBoolean(UObject* Holder, const FName Name, const bool Value, bool& Success)
{
	UObject* ValueStoreInterfaceObject = GetValueStoreObject(Holder, true);
	if (IsValid(ValueStoreInterfaceObject))
	{
		IValueStoreInterface::Execute_SetStoredBoolean(ValueStoreInterfaceObject, Name, Value);
		Success = true;
	}
	else
	{
		Success = false;
	}
}

void UValueStoreLibrary::GetStoredBoolean(UObject* Holder, const FName Name, bool& Found, bool& Value, bool& Success)
{
	UObject* ValueStoreInterfaceObject = GetValueStoreObject(Holder, true);
	if (IsValid(ValueStoreInterfaceObject))
	{
		IValueStoreInterface::Execute_GetStoredBoolean(ValueStoreInterfaceObject, Name, Found, Value);
		Success = true;
	}
	else
	{
		Value = false;
		Found = false;
		Success = false;
	}

}

void UValueStoreLibrary::DeleteStoredBoolean(UObject* Holder, const FName Name, bool& Success)
{
	// TODO: Implement
	Success = true;
}

#pragma endregion
#pragma region Integer
void UValueStoreLibrary::SetStoredInteger(UObject* Holder, const FName Name, const int Value, bool& Success)
{
	// TODO: Implement
	Success = true;
}

void UValueStoreLibrary::GetStoredInteger(UObject* Holder, const FName Name, bool& Found, int& Value, bool& Success)
{
	// TODO: Implement
	Value = 0;
	Success = true;
}

void UValueStoreLibrary::DeleteStoredInteger(UObject* Holder, const FName Name, bool& Success)
{
	// TODO: Implement
	Success = true;
}
#pragma endregion
