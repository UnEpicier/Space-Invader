#include "Player.h";

Player::Player(int screenSize): _screenSize(screenSize) {
	_shape = CircleShape(20, 3);
	_shape.setFillColor(Color(52, 252, 5));
	_shape.setPosition(Vector2f(_screenSize / 2, _screenSize - _shape.getScale().y - 50));
}

void Player::move(int direction) {
	float max = _screenSize - (_shape.getRadius() * 2);
	float result = 5 * direction;

	// Prevent leaving the window
	if (_shape.getPosition().x + result < 0 || _shape.getPosition().x + result > max) {
		result = 0;		
	}

	_shape.move(result, 0);
}