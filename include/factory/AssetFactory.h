#pragma once
#include <memory>
#include <interface/IFactory.h>
#include "object/Asset.h"
#include "object/SCF.h"

class AssetFactory : public IFactory
{
	void Destroy() override;
	AssetFactory();
	~AssetFactory() override;
public:
	static std::unique_ptr<Asset> CreateAsset(std::string assetID, std::string assetName);
};