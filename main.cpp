#include "character.h"
#include "enemy.h"
#include "prop.h"
#include "raylib.h"
#include "raymath.h"
#include <iostream>

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
  // Enemy
  Enemy goblin{Vector2{}, LoadTexture("characters/goblin_idle_spritesheet.png"), LoadTexture("goblin_run_spritesheet.png")};

  // array of Props
  Prop props[2]{
      Prop{LoadTexture("nature_tileset/Rock.png"), Vector2{600.f, 400.f}},
      Prop{LoadTexture("nature_tileset/Log.png"), Vector2{900.f, 600.f}}};

  SetTargetFPS(60);
  while (!WindowShouldClose()) {

    // Draw Canvas
    BeginDrawing();
    ClearBackground(WHITE);

    // move map around
    mapPos = Vector2Scale(knight.getWorldPos(), -1.f);

    // Draw World Map
    DrawTextureEx(map, mapPos, 0.f, mapScale, WHITE);

    // Draw props
    for (auto prop : props) {
      prop.Render(knight.getWorldPos());
    }

    // Draw character, movement/animation logic
    knight.tick(GetFrameTime());
    
    // Draw enemies, movement/animation logic
    goblin.tick(GetFrameTime());

    // check map bounds
    if (knight.getWorldPos().x < 0 || knight.getWorldPos().y < 0 ||
        knight.getWorldPos().x + canvasDimensions[0] > map.width * mapScale ||
        knight.getWorldPos().y + canvasDimensions[1] > map.height * mapScale) {
      knight.undoMovement();
    }

    // check collision for props
    for (auto prop : props) {
      if (CheckCollisionRecs(knight.getCollisionRec(), prop.getCollisionRec(knight.getWorldPos()))) {
        knight.undoMovement();
      }
    }
    
    // Stop Drawing Canvas
    EndDrawing();
  }

  UnloadTexture(map);
  knight.unloadTexture();

  CloseWindow();
}