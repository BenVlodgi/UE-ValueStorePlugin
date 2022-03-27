// Copyright Dream Seed LLC, 2022


#include "ValueStoreComponent.h"

UValueStoreComponent::UValueStoreComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

TScriptInterface<IValueStoreInterface> UValueStoreComponent::GetValueStoreObject_Implementation()
{
	return ValueStoreObjectReference;
}

void UValueStoreComponent::SetValueStoreObject_Implementation(const TScriptInterface<IValueStoreInterface>& ValueStore, bool& Success)
{
	ValueStoreObjectReference = ValueStore;
	Success = true;
}
