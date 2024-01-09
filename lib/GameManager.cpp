#include "GameManager.h";

GameManager::GameManager() {
	_window.setVerticalSyncEnabled(true);
}

void GameManager::run() {
	while (_window.isOpen()) {
		
		Event event;
		while (_window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				_window.close();
			}
		}

		// Handle user's inputs
		handleInputs();

		_window.clear(Color::Black);

		// Draw everything
		_window.draw(_player.getShape());

		for (vector<Laser *>::iterator it = _lasers.begin(); it < _lasers.end();) {
			_window.draw((*it)->getShape());

			(*it)->getShape().move(0, -5);

			if ((*it)->getShape().getPosition().y < -(*it)->getShape().getScale().y) {
				it = _lasers.erase(it);
				continue;
			}

			++it;
		}

		_window.display();
	}
}

void GameManager::handleInputs() {
	// Player movements
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Q)) {
		_player.move(-1);
	}

	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)) {
		_player.move(1);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if (_clock.getElapsedTime().asMilliseconds() > 500) {
			const Vector2f playerPos = _player.getShape().getPosition();
			const float playerRadius = _player.getShape().getRadius();

			Laser* laser = new Laser();
			laser->setInitialPosition(Vector2f(playerPos.x + playerRadius, playerPos.y - playerRadius));

			_lasers.push_back(laser);

			_clock.restart();
		}
	}
}