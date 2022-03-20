// Copyright Dream Seed LLC, 2022

#include "ValueStoreLibrary.h"
#include "ValueStoreSystem.h"

UValueStoreLibrary::UValueStoreLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

UValueStoreObject* UValueStoreLibrary::GetValueStoreObject(UObject* Holder, const bool bCreateIfMissing)
{
	if (!IsValid(Holder))
		return;

	UValueStoreComponent* ValueStoreComponent;

	// If the holder sent in is a UValueStoreComponent, then return it.
	ValueStoreComponent = Cast<UValueStoreComponent>(Holder);
	if (IsValid(ValueStoreComponent))
	{
		return ValueStoreComponent->;
	}

	// If the holder is an actor, look for ValueStoreComponent
	const AActor* HolderAsActor = Cast<AActor>(Holder);
	if (IsValid(HolderAsActor))
	{
		ValueStoreComponent = Cast<UValueStoreComponent>(HolderAsActor->GetComponentByClass(UValueStoreComponent::StaticClass()));
		return ValueStoreComponent;
	}
	

	if (!IsValid(ValueStoreComponent) && bCreateIfMissing)
	{
			//ValueStoreComponent = NewObject<UValueStoreComponent>(HolderAsActor); //TEXT("Value Store Component")
			ValueStoreComponent = CreateDefaultSubobject<UValueStoreComponent>(TEXT("Value Store Component"));
			ValueStoreComponent->RegisterComponent();

	}
	return ValueStoreComponent;
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
