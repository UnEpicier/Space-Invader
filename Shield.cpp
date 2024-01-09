#include "Shield.h"

Shield::Shield() {
	_shield = RectangleShape(Vector2f(30, 20));
	_shield.setFillColor(Color(52, 252, 5));
}

void Shield::decreaseLife()
{
	_life -= 1;
}
