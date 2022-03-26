// Copyright Dream Seed LLC, 2022


#include "ValueStoreComponent.h"

UValueStoreComponent::UValueStoreComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

TScriptInterface<IValueStoreInterface> UValueStoreComponent::GetValueStoreObject()
{
	return ValueStoreObjectReference;
}

void UValueStoreComponent::SetValueStoreObject(const TScriptInterface<IValueStoreInterface>& ValueStore, bool& Success)
{
	ValueStoreObjectReference = ValueStore;
	Success = true;
}
