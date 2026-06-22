#pragma once

class IFactory
{
public:
	IFactory() = default;
	virtual ~IFactory() = default;

private:
	virtual void Build(){};
	virtual void Destroy(){};
};