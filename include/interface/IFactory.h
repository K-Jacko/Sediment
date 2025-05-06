#pragma once

class IFactory
{
public:
	IFactory(){};
	virtual ~IFactory(){}

private:
	virtual void Build(){};
	virtual void Destroy(){};
};