#include "raylib.h"

class Enemy {
private:
public:
  // setters
  const void tick(const float deltaTime);
  const void undoMovement();

  // getters
  const Vector2 getWorldPos() const { return worldPos; }
  const Rectangle getCollisionRec();
};