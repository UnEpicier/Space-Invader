#include "Laser.h"

Laser::Laser()
{
	_laser = RectangleShape(Vector2f(4, 30));
	_laser.setFillColor(Color::White);
}

void Laser::setInitialPosition(Vector2f position) {
	_laser.setPosition(Vector2f(position.x - (_laser.getScale().x / 2), position.y));
}