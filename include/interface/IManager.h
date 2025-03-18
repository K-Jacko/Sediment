#pragma once
#include <cpprest/json.h>
#include <objbase.h>
#include <iostream>
#include <iomanip>

class IManager
{
	public:
	IManager() = default;
	virtual ~IManager() = default;
	virtual void Initialize();
	virtual void Update();
	GUID _id;
};