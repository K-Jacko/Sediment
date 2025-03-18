#include "../include/IManager.h"

void IManager::Initialize()
{
	if (CoCreateGuid(&_id) != S_OK) {
		std::cerr << "Failed to generate GUID." << std::endl;
	}
}
