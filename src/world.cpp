#include "../include/object/World.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "components/AnimationComponent.h"
#include "components/TransformComponent.h"

void World::addEntity(Entity e)
{
  _nextEntity++;
  _entities.push_back(e);
  std::cout << "Entity " << e.name << " Added to world" << std::endl;
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
  SCF* scf = DataManager::Instance()->getSCF();
  SpriteDetail* sd = scf->spriteDetails.getSpriteData("Player Turret");
  Entity e;
  e.id = 200;
  e.name = sd->name;
  AssetManager* am = AssetManager::Instance();
  WindowManager* wm = WindowManager::Instance();

  auto textureAsset = am->getTexture(sd->texture);
  SDL_Rect rec;
  rec.x = sd->crop.x;
  rec.y = sd->crop.y;
  rec.w = sd->crop.width;
  rec.h = sd->crop.height;

  if (textureAsset != nullptr)
  {
    addComponentToEntity(e, SpriteComponent{textureAsset, rec, e.id});
    addComponentToEntity(e, TransformComponent{static_cast<float>(sd->transform.x), static_cast<float>(sd->transform.y), static_cast<float>(sd->transform.width), static_cast<float>(sd->transform.height)});
    addEntity(e);
  }
  else
  {
    std::cout << "Error loading texture for SpriteComponent" << std::endl;
  }
  // Generate Grid
  _worldGrid = std::make_unique<Grid>(wm->defaultWindow()->GetWidth() / 64 , wm->defaultWindow()->GetHeight() / 64, 64);
  auto bottomRow = _worldGrid->getBottomRow();

  for (int i = 0; i < bottomRow.size(); i++)
  {
    SpriteDetail* sd = scf->spriteDetails.getSpriteData("Grass Tile");
    Entity e;
    e.id = 100 + i;
    e.name = sd->name;
    Vector2Int* position = bottomRow[i];
    auto tileTexture = am->getTexture(sd->texture);
    if (tileTexture != nullptr)
    {
      std::cout << " X:" << position->x << " Y:" << position->y << std::endl;
      addComponentToEntity(e, TransformComponent{static_cast<float>(position->x), static_cast<float>(position->y + 10), static_cast<float>(sd->transform.width), static_cast<float>(sd->transform.height)});
      addComponentToEntity(e, SpriteComponent{tileTexture, {sd->crop.x, sd->crop.y,sd->crop.width, sd->crop.height}, e.id});
      // ColliderComponent
      addEntity(e);
    }
  }

  for (int i = DataManager::Instance()->getSCF()->spriteDetails.backgrounds.size() - 1; i >= 0; --i)
  {
    Entity backGroundEntity;
    backGroundEntity.id = i;
    BackgroundDetail backgroundData = scf->spriteDetails.backgrounds[i];
    backGroundEntity.name = backgroundData.name;
    auto ta = am->getTexture(backgroundData.texture);
    int backgroundY = wm->defaultWindow()->GetHeight() - (backgroundData.height * backgroundData.scale);
    if (ta != nullptr)
    {
      addComponentToEntity(backGroundEntity, TransformComponent{0, static_cast<float>(backgroundY), static_cast<float>(backgroundData.width), static_cast<float>(backgroundData.height), backgroundData.scale});
      addComponentToEntity(backGroundEntity, SpriteComponent{ta, {0,0,backgroundData.width, backgroundData.height}, static_cast<std::uint32_t>(i)});
      addComponentToEntity(backGroundEntity, AnimationComponent{10, 10, 1, static_cast<AnimationType>(backgroundData.animationType), backgroundY});
      addEntity(backGroundEntity);
    }
    else
    {
      std::cout << "Failed to load texture: " << backgroundData.texture << std::endl;
    }
  }
}
