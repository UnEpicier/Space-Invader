#include "Player.h";

Player::Player(Vector2u screenSize): _screenWidth(screenSize.x) {
	_shape = CircleShape(40, 3);
	_shape.setFillColor(Color(52, 252, 5));
	_shape.setPosition(_screenWidth / 2.f, screenSize.y - _shape.getScale().y - 50);
}

void Player::move(int direction) {
	float max = _screenWidth - (_shape.getRadius() * 2);
	float result = 5 * direction;

	// Prevent leaving the window
	if (_shape.getPosition().x + result < 0 || _shape.getPosition().x + result > max) {
		result = 0;
	}

	_shape.move(result, 0);
}