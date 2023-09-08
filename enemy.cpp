#include "enemy.h"

Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture) {
  worldPos = pos;
  texture = idle_texture;
  idle = idle_texture;
  run = run_texture;
  width = static_cast<float>(texture.width) / maxFrames;
  height = static_cast<float>(texture.height);
}

const void Enemy::tick(const float deltaTime) {
  BaseCharacter::tick(deltaTime);
}
