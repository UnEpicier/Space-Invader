#include "Shield.h"

Shield::Shield(Window& window) {
	int shapeWidth = window.getSize().x / 10;
	int shapeHeight = window.getSize().y / 35;

	_shape = RectangleShape(Vector2f(shapeWidth, shapeHeight));
	_shape.setFillColor(Color(Color(52, 252, 5)));
}

void Shield::setPosition(Vector2f position) {
	_shape.setPosition(position.x + _shape.getSize().x, position.y - _shape.getScale().y);
}