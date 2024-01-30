#include "Alien.h"

Alien::Alien(Vector2f& position) {
	_shape = RectangleShape(Vector2f(100, 50));
	_shape.setFillColor(Color::Red);
	_shape.setPosition(Vector2f(position.x - (_shape.getScale().x / 2.0), position.y));
}