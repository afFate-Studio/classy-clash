#ifndef _PROP_H_
#define _PROP_H_

#include "raylib.h"

class Prop {
private:
  Texture2D texture{};
  Vector2 worldPos{};
  const float scale{4.f};

public:
  Prop(Texture2D tex, Vector2 pos);
  void Render(Vector2 knightPos);
  const Rectangle getCollisionRec(Vector2 knightPos);
};

#endif