#include "Laser.h"

Laser::Laser(Window& _window)
{
	_laser = RectangleShape(Vector2f(_window.getSize().x / 600, _window.getSize().y / 30));
	_laser.setFillColor(Color::White);
}

void Laser::setInitialPosition(Vector2f position) {
	_laser.setPosition(Vector2f(position.x - (_laser.getScale().x / 2), position.y));
}