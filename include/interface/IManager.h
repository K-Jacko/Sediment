#pragma once

class IManager
{
	public:
	virtual ~IManager() = default;
	virtual bool Initialize(){ return false; }
	virtual void Update(){}
};
