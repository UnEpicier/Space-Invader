#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Laser.h"
#include "Shield.h"

using namespace std;
using namespace sf;

class GameManager
{
public:
	GameManager();

	void run();
	void handleInputs();
	void handleLasersCollision();

private:
	Clock _clock;

	//RenderWindow _window{ VideoMode::getFullscreenModes()[0], "Space Invader", Style::Fullscreen };
	RenderWindow _window{ VideoMode(1024, 800), "Space Invader", Style::Close | Style::Titlebar};

	Player _player = { _window.getSize() };

	vector<Laser*> _lasers;
	vector<Shield*> _shields;
};

