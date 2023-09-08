#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "BaseCharacter.h"
class Enemy : public BaseCharacter {
private:

public:
  // constructor & destructor
  Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);

  // setters
  const virtual void tick(const float deltaTime) override;
};

#endif