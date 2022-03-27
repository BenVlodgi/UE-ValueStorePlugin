// Copyright Dream Seed LLC, 2022

#include "ValueStoreLibrary.h"
#include "ValueStoreSystem.h"

UValueStoreLibrary::UValueStoreLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

UObject* UValueStoreLibrary::GetValueStoreObject(UObject* Holder, const bool bCreateIfMissing)
{
	if (!IsValid(Holder))
		return NULL;

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
				// TODO: Warn that Holder does not set value store object correctly.
				//UE_LOG(LogTemp, Warning, TEXT("Holder does not set value store object correctly."));
			}

			UObject* ValueStoreInterfaceObject_Set = IValueStoreHolderInterface::Execute_GetValueStoreObject(Holder).GetObject();
			if (ValueStoreInterfaceObject != ValueStoreInterfaceObject_Set)
			{
				// TODO: Warn that Holder does not return the ValueStore we just set!
				//UE_LOG(LogTemp, Warning, TEXT("Holder does not return the ValueStore we just set!"));

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
			UComponent* Component = HolderAsActor->GetComponentByInterface(UValueStoreInterface::StaticClass());
			if (IsValid(Component))
			{
				return Component;
			}
			
			// Get Component from Actor that implements ValueStoreHolderInterface
			Component = HolderAsActor->GetComponentByInterface(UValueStoreHolderInterface::StaticClass());
			if (IsValid(Component))
			{
				return GetValueStoreObject(Component, bCreateIfMissing);
			}
			else if(bCreateIfMissing)
			{
				Component = NewObject<UValueStoreComponent>(HolderAsActor);
				Component->RegisterComponent();
				return GetValueStoreObject(Component, bCreateIfMissing);
			}
		}
		else
		{
			// This Holder, does not implement either interface, and is not an actor, there is no way we can get a ValueStore from it.
			return NULL;
		}
	}



	// If the holder sent in is a UValueStoreComponent, then return it.
	//UValueStoreComponent* ValueStoreComponent = Cast<UValueStoreComponent>(Holder);
	//if (IsValid(ValueStoreComponent))
	//{
	//	return ValueStoreComponent->ValueStoreObject;
	//}

	// If the holder is an actor, look for ValueStoreComponent
	//const AActor* HolderAsActor = Cast<AActor>(Holder);
	//if (IsValid(HolderAsActor))
	//{
	//	ValueStoreComponent = Cast<UValueStoreComponent>(HolderAsActor->GetComponentByClass(UValueStoreComponent::StaticClass()));
	//	return ValueStoreComponent;
	//}
	//
	//
	//if (!IsValid(ValueStoreComponent) && bCreateIfMissing)
	//{
	//		//ValueStoreComponent = NewObject<UValueStoreComponent>(HolderAsActor); //TEXT("Value Store Component")
	//		ValueStoreComponent = CreateDefaultSubobject<UValueStoreComponent>(TEXT("Value Store Component"));
	//		ValueStoreComponent->RegisterComponent();
	//
	//}
	//return ValueStoreComponent;

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
