#include "character.h"
#include "raymath.h"
#include <cstring>

// no-args constructor
Character::Character(int canvasWidth, int canvasHeight) {
  width = static_cast<float>(texture.width) / maxFrames;
  height = static_cast<float>(texture.height);
  screenPos.x =
      static_cast<float>(canvasWidth) / 2.f - scale * (0.5f * width / 2.f);
  screenPos.y =
      static_cast<float>(canvasHeight) / 2.f - scale * (0.5f * height);
}

const void Character::tick(const float deltaTime) {
  // call parent tick function
  BaseCharacter::tick(deltaTime);

  // check for movement inputs
  Vector2 direction{};
  if (IsKeyDown(KEY_W))
    direction.y -= 1.f;
  if (IsKeyDown(KEY_A))
    direction.x -= 1.f;
  if (IsKeyDown(KEY_S))
    direction.y += 1.f;
  if (IsKeyDown(KEY_D))
    direction.x += 1.f;

  // if movement switch texture to run, move character, base looking direction on movement
  if (Vector2Length(direction) != 0.f) {
    texture = run;
    worldPos =
        Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
    direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
  } else {
    texture = idle;
  }
}
