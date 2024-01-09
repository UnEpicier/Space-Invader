#pragma once

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Laser.h"

using namespace std;
using namespace sf;

class GameManager
{
public:
	GameManager();

	void run();
	void handleInputs();

private:
	Clock _clock;

	RenderWindow _window{ VideoMode::getFullscreenModes()[0], "Space Invader", Style::Fullscreen };

	Player _player = { _window.getSize() };

	vector<Laser *> _lasers;
};

