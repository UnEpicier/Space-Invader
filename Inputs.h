#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h";

using namespace std;
using namespace sf;

class Inputs
{
public:
	Inputs(RenderWindow& window, Player& player) : _window(window), _player(player) {};

	void HandleInputs(Event& event);

private:
	RenderWindow& _window;
	Player& _player;
};

