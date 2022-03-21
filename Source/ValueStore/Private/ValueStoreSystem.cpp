// Copyright Dream Seed LLC, 2022

#include "ValueStoreSystem.h"

#define LOCTEXT_NAMESPACE "FValueStoreSystem"

void FValueStoreSystem::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FValueStoreSystem::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FValueStoreSystem, ValueStoreSystem)