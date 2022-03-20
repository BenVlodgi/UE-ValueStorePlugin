// Copyright Benjamin Thomas Blodgett

#pragma once

#include "Modules/ModuleManager.h"

class FValueStoreSystem : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
