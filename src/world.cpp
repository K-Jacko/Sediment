#include "../include/object/World.h"
#include "AssetManager.h"
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
    e.id = i;
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
      addComponentToEntity(e, TransformComponent{spriteData.transform.x, spriteData.transform.y, spriteData.transform.width, spriteData.transform.height});
      addEntity(e);
    }
    else
    {
      std::cout << "Error loading texture for SpriteComponent" << std::endl;
    }
  }
}
