#include "character.h"
#include "raylib.h"
#include "raymath.h"

int main() {

  const int canvasDimensions[2]{1280, 720};
  const char *title{"Classy Clash"};
  InitWindow(canvasDimensions[0], canvasDimensions[1], title);

  // World Map
  Texture2D map{LoadTexture("nature_tileset/WorldMap.png")};
  Vector2 mapPos{0.0, 0.0};

  // Character
  Character knight{};
  knight.setScreenPos((float)canvasDimensions[0] / 2.f -
                          4.f * (0.5f * (float)knight.getWidth() / 2.f),
                      (float)canvasDimensions[1] / 2.f -
                          4.f * (0.5f * (float)knight.getHeight()));

  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    // Draw Canvas
    BeginDrawing();
    ClearBackground(WHITE);

    // move map around
    mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

    // Draw World Map
    DrawTextureEx(map, mapPos, 0.f, 4.f, WHITE);

    // Draw character, movement/animation logic
    knight.tick(GetFrameTime());

    // Stop Drawing Canvas
    EndDrawing();
  }

  UnloadTexture(map);
  knight.unloadTexture();

  CloseWindow();
}