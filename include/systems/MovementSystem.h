#include "../interface/ISystem.h"

class MovementSystem : public ISystem
{
  public:
    MovementSystem() = default;
    void update() override;
};
