#pragma once

class IManager
{
	public:
	IManager(){}
	virtual ~IManager(){};
	virtual bool Initialize(){ return false; }
	virtual void Update(){}
};
