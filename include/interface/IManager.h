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
	virtual void Initialize()
	{
		if (CoCreateGuid(&_id) != S_OK) {
			std::cerr << "Failed to generate GUID." << std::endl;
		}
	}
	virtual void Update();
	GUID _id;
};