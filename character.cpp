#include "character.h"
#include "raymath.h"
#include <cstring>

// no-args constructor
Character::Character(int w, int h) : file_name{nullptr} {
  file_name = new char[1];
  *file_name = '\0';
  width = (float)texture.width / maxFrames;
  height = (float)texture.height;
  canvasWidth = w;
  canvasHeight = h;
  screenPos.x = (float)canvasWidth / 2.f - 4.f * (0.5f * width / 2.f);
  screenPos.y = (float)canvasHeight / 2.f - 4.f * (0.5f * height);
}

// overloaded constructor
Character::Character(int w, int h, char *s) : file_name{nullptr} {
  if (s == nullptr) {
    file_name = new char[1];
    *file_name = '\0';
  } else {
    file_name = new char[std::strlen(s) + 1];
    std::strcpy(file_name, s);
    width = (float)texture.width / maxFrames;
    height = (float)texture.height;
    canvasWidth = w;
    canvasHeight = h;
    screenPos.x = (float)canvasWidth / 2.f - 4.f * (0.5f * width / 2.f);
    screenPos.y = (float)canvasHeight / 2.f - 4.f * (0.5f * height);
  }
}

// destructor
Character::~Character() { delete[] file_name; }

// setters
// default no args sprite texture
void Character::setTexture(Texture2D texture) { Character::texture = texture; }

// idle sprite texture
void Character::setIdle(Texture2D idleTexture, const char *file_name) {
  Character::idle = idleTexture;
  Character::idle = LoadTexture(file_name);
}

// running sprite texture
void Character::setRun(Texture2D runTexture, const char *file_name) {
  Character::run = runTexture;
  Character::run = LoadTexture(file_name);
}

// unloading Texture2D
void Character::unloadTexture() {
  UnloadTexture(Character::texture);
  UnloadTexture(Character::idle);
  UnloadTexture(Character::run);
}

const void Character::tick(const float deltaTime) {
  worldPosLastFrame = worldPos;

  Vector2 direction{};
  if (IsKeyDown(KEY_W))
    direction.y -= 1.f;
  if (IsKeyDown(KEY_A))
    direction.x -= 1.f;
  if (IsKeyDown(KEY_S))
    direction.y += 1.f;
  if (IsKeyDown(KEY_D))
    direction.x += 1.f;

  if (Vector2Length(direction) != 0.f) {
    texture = run;
    worldPos =
        Vector2Add(worldPos, Vector2Scale(Vector2Normalize(direction), speed));
    direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;
  } else {
    texture = idle;
  }

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

  Rectangle dest{screenPos.x, screenPos.y, 4.f * width, 4.f * height};

  // Draw character
  DrawTexturePro(texture, source, dest, Vector2{}, 0.f,
                 WHITE); // drawing idle knight sprite
}

const void Character::undoMovement() { worldPos = worldPosLastFrame; }

// getters
const Texture2D Character::getTexture() const { return texture; }
const Texture2D Character::getIdle() const { return idle; }
const Texture2D Character::getRun() const { return run; }
const int Character::getHeight() const { return height; }
const int Character::getWidth() const { return Character::texture.width; }
const float Character::getRightLeft() const { return rightLeft; }
const Vector2 Character::getWorldPos() const { return worldPos; }
