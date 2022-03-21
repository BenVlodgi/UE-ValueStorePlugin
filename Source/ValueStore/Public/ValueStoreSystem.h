// Copyright Dream Seed LLC, 2022

#pragma once

#include "Modules/ModuleManager.h"

class FValueStoreSystem : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
