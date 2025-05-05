#pragma once
#include <nlohmann/json.hpp>
#include <objbase.h>
#include <iostream>
#include <iomanip>

class IManager
{
	public:
	IManager(){}
	virtual ~IManager(){};
	virtual void Initialize(){}
	virtual void Update(){}
};