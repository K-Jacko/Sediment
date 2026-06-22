#include "Asset.h"
#include <SDL.h>

class TextureAsset : public Asset
{
public:
    TextureAsset(SDL_Texture* texture, const std::string& id, const std::string& name, const std::string& path);
    ~TextureAsset();
    SDL_Texture* getTexture() const;
private:
    bool isSprite = false;
    bool isCached = false;
    SDL_Texture* _texture = nullptr;
};
