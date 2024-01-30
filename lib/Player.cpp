#include "Player.h";

Player::Player(Vector2u screenSize): _screenWidth(screenSize.x) {
	_shape = CircleShape(screenSize.x / 70, 3);
	_shape.setFillColor(Color(52, 252, 5));

	float shapeHeight = _shape.getRadius() * 1.5;

	_shape.setPosition(_screenWidth / 2.f, screenSize.y - shapeHeight);
}

void Player::move(int direction) {
	float max = _screenWidth - (_shape.getRadius() * 2);
	float result = (_screenWidth / 724.0)*direction;

	// Prevent leaving the window
	if (_shape.getPosition().x + result < 0 || _shape.getPosition().x + result > max) {
		result = 0;
	}

	_shape.move(result, 0);
}