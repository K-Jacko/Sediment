#include "../include/object/TextureAsset.h"


TextureAsset::~TextureAsset()
{
  if (_texture)
  {
    SDL_DestroyTexture(_texture);
  }
}

TextureAsset::TextureAsset(SDL_Texture* texture, const std::string& id, const std::string& name, const std::string& path)
{
    _id = id;
    _name = name;
    _texture = texture;
}

SDL_Texture* TextureAsset::getTexture()
{
  return _texture;
}
