#include "Asset.h"

class TextureAsset : public Asset
{
public:
    TextureAsset(const std::string& id, const std::string& name, const std::string& path);
private:
    bool isSprite = false;
    bool isCached = false;
};
