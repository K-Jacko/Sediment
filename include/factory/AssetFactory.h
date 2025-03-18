#pragma once
#include <SDL_render.h>
#include <vector>
#include <interface/IFactory.h>

class AssetFactory : public IFactory
{
	void Build() override;
	void Destroy() override;
	AssetFactory();
	~AssetFactory() override;
public:
	void Initialize();
	SDL_Texture* LoadSprite();

private:
	std::vector<SDL_Texture*> _sprites;

};