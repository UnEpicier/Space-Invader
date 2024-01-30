#include "GameManager.h"

GameManager::GameManager() {
	_window.setVerticalSyncEnabled(true);

	for (int i = 0; i < 4; i++) {
		Shield* shield = new Shield(_window);
		shield->setPosition(Vector2f(_window.getSize().x / 4.25f * i, _window.getSize().y * 0.9f));

		_shields.push_back(shield);
	}

	const int rows = 3;
	const int cols = 6;
	const int distX = 135;
	const int distY = 85;

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			Vector2f position(col * distX + alienScreenMargin + 1, row * distY + alienScreenMargin);
			Alien* alien = new Alien(position);

			_aliens.push_back(alien);
		}
	}
}

void GameManager::run() {
	int alienDirection = 1;
	const float alienXStep = 10;
	const int moveDownStep = 5;
	int moveDown = 0;

	Clock alienClock;

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

		for (Alien* alien : _aliens) {
			const FloatRect bounds = alien->getShape().getGlobalBounds();

			if (bounds.left + bounds.width >= _window.getSize().x - alienScreenMargin || bounds.left <= alienScreenMargin) {
				alienDirection *= -1;
				moveDown = moveDownStep;
				break;
			}
		}

		for (Alien* alien : _aliens) {
			_window.draw(alien->getShape());
		}


		if (alienClock.getElapsedTime().asMilliseconds() >= 500) {
			for (Alien* alien : _aliens) {
				alien->getShape().move(alienXStep * alienDirection, moveDown);
			}
			alienClock.restart();
		}
		moveDown = 0;


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

		for (vector<Alien*>::iterator alienIt = _aliens.begin(); alienIt < _aliens.end();) {
			if ((*laserIt)->getShape().getGlobalBounds().intersects((*alienIt)->getShape().getGlobalBounds())) {
				delete* alienIt;
				alienIt = _aliens.erase(alienIt);
				deleteLaser = true;
				break;
			}
			++alienIt;
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