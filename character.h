#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "BaseCharacter.h"

class Character : public BaseCharacter {
private:
public:
  // constructors
  Character(int canvasWidth, int canvasHeight); // canvas width/height

  // setters
  const virtual void tick(const float deltaTime) override;
};

#endif // _CHARACTER_H_