#pragma once
#include <memory>
#include <interface/IFactory.h>
#include "object/TextureAsset.h"
#include "object/SCF.h"

class AssetFactory : public IFactory
{
  public:
	void Destroy() override;
	AssetFactory();
	~AssetFactory() override;
	static std::unique_ptr<Asset> CreateAsset(std::string assetID, std::string assetName);
};
