#include "BaseCharacter.h"

BaseCharacter::BaseCharacter() {}

// unloading Texture2D
void BaseCharacter::unloadTexture() {
  UnloadTexture(BaseCharacter::texture);
  UnloadTexture(BaseCharacter::idle);
  UnloadTexture(BaseCharacter::run);
}

const void BaseCharacter::undoMovement() { worldPos = worldPosLastFrame; }

const void BaseCharacter::tick(const float deltaTime) {
  worldPosLastFrame = worldPos;
  // update animation
  runningTime += deltaTime;
  if (runningTime >= updateTime) {
    frame++;
    runningTime = 0.f;
    if (frame > maxFrames) {
      frame = 0;
    }
  }

  Rectangle source{frame * width, 0.f, rightLeft * width, height};

  Rectangle dest{screenPos.x, screenPos.y, scale * width, scale * height};

  // Draw character
  DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

const Rectangle BaseCharacter::getCollisionRec() {
  return Rectangle{screenPos.x, screenPos.y, width * scale, height * scale};
}