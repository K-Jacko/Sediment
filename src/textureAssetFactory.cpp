#include "WindowManager.h"
#include "factory/TextureAssetFactory.h"
#include <string>
#include <SDL_surface.h>
#include <SDL_render.h>
#include <SDL_image.h>

TextureAssetFactory::TextureAssetFactory(){}

std::unique_ptr<TextureAsset> TextureAssetFactory::createFromFile(std::string id, std::string name, std::string path)
{
    auto baseAsset = CreateAsset(id, name);

    std::string fullPath = std::string(PROJECT_ROOT) + "/" + path;
    SDL_Surface* rawSurface = IMG_Load(fullPath.c_str());

    if (rawSurface)
    {
        SDL_Texture* rawTexture = SDL_CreateTextureFromSurface(WindowManager::Instance()->defaultWindow()->getRenderer(), rawSurface);
        if (rawTexture)
        {
            auto textureAsset = std::make_unique<TextureAsset>(rawTexture, id, name, path);
           // textureAsset->setTexture(rawTexture);

            return textureAsset;
        }
        SDL_Log("Failed to create texture: %s", SDL_GetError());
    }
    SDL_Log("Failed to load surface: %s", IMG_GetError());
    
    return nullptr;
}

TextureAssetFactory::~TextureAssetFactory(){}
