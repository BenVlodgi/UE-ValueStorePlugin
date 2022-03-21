// Copyright Dream Seed LLC, 2022

#include "ValueStoreLibrary.h"
#include "ValueStoreSystem.h"

UValueStoreLibrary::UValueStoreLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

TScriptInterface<IValueStoreInterface> UValueStoreLibrary::GetValueStore(UObject* Holder, const bool bCreateIfMissing)
{
	if (!IsValid(Holder))
		return NULL;

	//// If the holder implements IValueStoreInterface, then return it. 
	//IValueStoreInterface* ValueStoreInterface = Cast<IValueStoreInterface>(Holder);
	//if (IsValid(ValueStoreInterface))
	//{
	//	return ValueStoreInterface;
	//}
	//
	//// If the holder implements IValueStoreHolderInterface, then get the IValueStoreInterface object from it. 
	//IValueStoreHolderInterface* ValueStoreHolderInterface = Cast<IValueStoreHolderInterface>(Holder);
	//if (IsValid(ValueStoreHolderInterface))
	//{
	//	return ValueStoreInterface;
	//}



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

void UValueStoreLibrary::SetStoredBoolean(UObject* Holder, const FName Name, const bool Value, bool& Success)
{
	Success = true;
}

void UValueStoreLibrary::GetStoredBoolean(UObject* Holder, const FName Name, bool& Found, bool& Value, bool& Success)
{
	Value = false;
	Success = true;
}

void UValueStoreLibrary::DeleteStoredBoolean(UObject* Holder, const FName Name, bool& Success)
{
	Success = true;
}
