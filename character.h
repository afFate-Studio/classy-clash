#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "raylib.h"

class Character {
private:
  Texture2D texture{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D idle{LoadTexture("characters/knight_idle_spritesheet.png")};
  Texture2D run{LoadTexture("characters/knight_run_spritesheet.png")};
  char *file_name{};
  Vector2 screenPos{};
  Vector2 worldPos{};

  // animation variables
  float rightLeft{1.f}; // Left : -1.f & right : 1.f
  int frame{};
  const int maxFrames{6};
  float runningTime{};
  float updateTime{1.f / 12.f};
  float width{};
  float height{};
  
  // physics
  const float speed{4.0};

public:
  // constructors & destructor
  Character();
  Character(char *s);
  ~Character();

  // setters
  void setTexture(Texture2D texture);
  void setIdle(Texture2D idleTexture, const char *file_name);
  void setRun(Texture2D runTexture, const char *file_name);
  void setScreenPos(float posX, float posY);
  void unloadTexture();
  const void tick(const float deltaTime);

  // getters
  const Texture2D getTexture() const;
  const Texture2D getIdle() const;
  const Texture2D getRun() const;
  const int getHeight() const;
  const int getWidth() const;
  const float getRightLeft() const;
  const Vector2 getWorldPos() const;
};

#endif // _CHARACTER_H_