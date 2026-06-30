#include "../include/object/World.h"
#include "AssetManager.h"
#include "WindowManager.h"
#include "components/AnimationComponent.h"
#include "components/ColliderComponent.h"
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
  SpriteDetail* turretDetails = scf->spriteDetails.getSpriteData("Player Turret");
  Entity e;
  e.id = 200;
  e.name = turretDetails->name;
  AssetManager* am = AssetManager::Instance();
  WindowManager* wm = WindowManager::Instance();

  auto textureAsset = am->getTexture(turretDetails->texture);

  if (textureAsset != nullptr)
  {
  addComponentToEntity(e, SpriteComponent{textureAsset, {turretDetails->crop.x, turretDetails->crop.y,turretDetails->crop.width, turretDetails->crop.height}, e.id});
    addComponentToEntity(e, TransformComponent{static_cast<float>(turretDetails->transform.x), static_cast<float>(turretDetails->transform.y), static_cast<float>(turretDetails->transform.width), static_cast<float>(turretDetails->transform.height)});
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
    Entity gt;
    gt.id = 100 + i;
    gt.name = sd->name;
    Vector2Int* position = bottomRow[i];
    auto tileTexture = am->getTexture(sd->texture);
    if (tileTexture != nullptr)
    {
      std::cout << " X:" << position->x << " Y:" << position->y << std::endl;
      addComponentToEntity(gt, TransformComponent{static_cast<float>(position->x), static_cast<float>(position->y + 10), static_cast<float>(sd->transform.width), static_cast<float>(sd->transform.height)});
      addComponentToEntity(gt, SpriteComponent{tileTexture, {sd->crop.x, sd->crop.y,sd->crop.width, sd->crop.height}, e.id});
      addComponentToEntity(gt, ColliderComponent{});
      addEntity(gt);
    }
  }

  SpriteDetail* playerDetail = scf->spriteDetails.getSpriteData("Player");
  Entity player;
  player.id = 999;
  player.name = playerDetail->name;
  auto playerTexture = am->getTexture(playerDetail->texture);
  addComponentToEntity(player, TransformComponent{static_cast<float>(playerDetail->transform.x), static_cast<float>(playerDetail->transform.y), static_cast<float>(playerDetail->transform.width), static_cast<float>(playerDetail->transform.height), 4});
  addComponentToEntity(player, SpriteComponent{playerTexture, {playerDetail->crop.x, playerDetail->crop.y,playerDetail->crop.width, playerDetail->crop.height}, player.id});
  addComponentToEntity(player, ColliderComponent{});
  addEntity(player);


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
