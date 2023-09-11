#include "enemy.h"
#include "raymath.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) {
  worldPos = pos;
  texture = idle_texture;
  idle = idle_texture;
  run = run_texture;
  width = static_cast<float>(texture.width) / maxFrames;
  height = static_cast<float>(texture.height);
  speed = 3.5f;
}

void Enemy::tick(const float deltaTime) {
  // get screenPos, then normalize it
  toTarget =
      Vector2Normalize(Vector2Subtract(target->getScreenPos(), screenPos));

  // set speed
  toTarget = Vector2Scale(toTarget, speed);

  // move ai
  worldPos = Vector2Add(worldPos, toTarget);

  screenPos = Vector2Subtract(worldPos, target->getWorldPos());

  BaseCharacter::tick(deltaTime);
}

void Enemy::SetTarget(Character *character) { target = character; }
