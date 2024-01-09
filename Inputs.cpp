#include "Inputs.h"

void Inputs::HandleInputs() {
	// Player movements
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Q)) {
		_player.move(-1);
	}

	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
		_player.move(1);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if (_clock.getElapsedTime().asMilliseconds() > 500) {
			const Vector2f playerPos = _player.PlayerShape.getPosition();
			const float playerRadius = _player.PlayerShape.getRadius();

			Laser laser;
			laser.setInitialPosition(Vector2f(playerPos.x + playerRadius, playerPos.y - playerRadius));

			_lasers.push_back(laser.getLaser());

			_clock.restart();
		}

	}
}