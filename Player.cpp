#include "Player.h";

void Player::drawPlayer() {
	PlayerShape.setFillColor(Color(52, 252, 5));
	PlayerShape.setPosition(Vector2f(_window.getSize().x / 2 + _x, _window.getSize().y - PlayerShape.getScale().y - 50));

	_window.draw(PlayerShape);
}

void Player::move(int direction) {
	int result = _x + _velocity * direction;

	int minX = _window.getSize().x / 2 * -1;
	int maxX = _window.getSize().x / 2 - ((int)PlayerShape.getRadius() * 2);

	if (result < minX) {
		result = minX;
	}
	else if (result > maxX) {
		result = maxX;
	}
	else {
		_x = result;
	}
}