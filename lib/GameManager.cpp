#include "GameManager.h";

GameManager::GameManager() {
	_window.setVerticalSyncEnabled(true);

	for (int i = 0; i < 4; i++) {
		Shield* shield = new Shield(_window);
		shield->setPosition(Vector2f(_window.getSize().x / 4.25 * i, _window.getSize().y * 0.9));

		_shields.push_back(shield);
	}
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

		for (auto shield : _shields) {
			_window.draw(shield->getShape());
		}

		for (vector<Laser *>::iterator it = _lasers.begin(); it < _lasers.end();) {
			_window.draw((*it)->getShape());

			(*it)->getShape().move(0, -5);

			if ((*it)->getShape().getPosition().y < -(*it)->getShape().getScale().y) {
				delete* it;
				it = _lasers.erase(it);
				continue;
			}

			++it;
		}

		handleLasersCollision();

		_window.display();
	}
}

void GameManager::handleInputs() {
	// Exit event
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		_window.close();
	}

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

			Laser* laser = new Laser(_window);
			laser->setInitialPosition(Vector2f(playerPos.x + playerRadius, playerPos.y - playerRadius));

			_lasers.push_back(laser);

			_clock.restart();
		}
	}
}

void GameManager::handleLasersCollision() {
	bool restartClock = false;
	for (vector<Laser*>::iterator laserIt = _lasers.begin(); laserIt < _lasers.end();) {
		bool deleteLaser = false;
		for (vector<Shield*>::iterator shieldIt = _shields.begin(); shieldIt < _shields.end();) {
			if ((*laserIt)->getShape().getGlobalBounds().intersects((*shieldIt)->getShape().getGlobalBounds())) {
				if ((*shieldIt)->getLife() - 1 == 0) {
					delete* shieldIt;
					shieldIt = _shields.erase(shieldIt);
				}

				(*shieldIt)->decreaseLife();
				deleteLaser = true;
				break;
			}
			++shieldIt;
		}

		if (deleteLaser) {
			delete* laserIt;
			laserIt = _lasers.erase(laserIt);

			restartClock = true;
			continue;
		}

		++laserIt;
	}

	if (restartClock) {
		_clock.restart();
	}
}