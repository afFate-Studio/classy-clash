#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "BaseCharacter.h"
#include "character.h"
class Enemy : public BaseCharacter {
private:
  Character *target{};
  Vector2 toTarget{};

public:
  // constructor & destructor
  Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture);

  // setters
  virtual void tick(const float deltaTime) override;
  void SetTarget(Character *character);
};

#endif