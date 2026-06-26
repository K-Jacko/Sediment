#include "../include/object/World.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "components/AnimationComponent.h"
#include "components/TransformComponent.h"

void World::addEntity(Entity e)
{
  _nextEntity++;
  _entities.push_back(e);
  std::cout << "Entity Added to world" << std::endl;
}

std::vector<Entity> World::getEntities()
{
  return _entities;
}

void World::updateSystems()
{
  for (std::unique_ptr<ISystem>& sys : _systems)
  {
    sys->update();
  }
}

void World::start()
{
  for (int i = 0; i < DataManager::Instance()->getSCF()->spriteDetails.sprites.size(); i++)
  {
    Entity e;
    e.id = i + 10;
    AssetManager* am = AssetManager::Instance();
    SCF* scf = DataManager::Instance()->getSCF();
    SpriteDetail spriteData = scf->spriteDetails.sprites[i];
    auto textureAsset = am->getTexture(spriteData.texture);
    SDL_Rect rec;
    rec.x = spriteData.crop.x;
    rec.y = spriteData.crop.y;
    rec.w = spriteData.crop.width;
    rec.h = spriteData.crop.height;

    if (textureAsset != nullptr)
    {
      addComponentToEntity(e, SpriteComponent{textureAsset, rec});
      addComponentToEntity(e, TransformComponent{static_cast<float>(spriteData.transform.x), static_cast<float>(spriteData.transform.y), static_cast<float>(spriteData.transform.width), static_cast<float>(spriteData.transform.height)});
      addEntity(e);
    }
    else
    {
      std::cout << "Error loading texture for SpriteComponent" << std::endl;
    }
  }

  for (int i = DataManager::Instance()->getSCF()->spriteDetails.backgrounds.size() - 1; i >= 0; --i)
  {
    Entity e;
    e.id = i;
    AssetManager* am = AssetManager::Instance();
    WindowManager* wm = WindowManager::Instance();
    SCF* scf = DataManager::Instance()->getSCF();
    BackgroundDetail backgroundData = scf->spriteDetails.backgrounds[i];
    auto textureAsset = am->getTexture(backgroundData.texture);
    int backgroundY = wm->defaultWindow()->GetHeight() - (backgroundData.height * backgroundData.scale);
    if (textureAsset != nullptr)
    {
      addComponentToEntity(e, TransformComponent{0, static_cast<float>(backgroundY), static_cast<float>(backgroundData.width), static_cast<float>(backgroundData.height), backgroundData.scale});
      addComponentToEntity(e, SpriteComponent{textureAsset, {0,0,backgroundData.width, backgroundData.height}});
      addComponentToEntity(e, AnimationComponent{10, 10, 1, static_cast<AnimationType>(backgroundData.animationType), backgroundY});
      addEntity(e);
    }
    else
    {
      std::cout << "Failed to load texture: " << backgroundData.texture << std::endl;
    }
  }
}
