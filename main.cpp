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
  const float mapScale{4.f};

  // Character
  Character knight{canvasDimensions[0], canvasDimensions[1]};

  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    // Draw Canvas
    BeginDrawing();
    ClearBackground(WHITE);

    // move map around
    mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

    // Draw World Map
    DrawTextureEx(map, mapPos, 0.f, mapScale, WHITE);

    // Draw character, movement/animation logic
    knight.tick(GetFrameTime());

    // check map bounds
    if (knight.getWorldPos().x < 0 || knight.getWorldPos().y < 0 ||
        knight.getWorldPos().x + canvasDimensions[0] > map.width * mapScale ||
        knight.getWorldPos().y + canvasDimensions[1] > map.height * mapScale) {
      knight.undoMovement();
    }

    // Stop Drawing Canvas
    EndDrawing();
  }

  UnloadTexture(map);
  knight.unloadTexture();

  CloseWindow();
}