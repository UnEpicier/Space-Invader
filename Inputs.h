#pragma once

#include <list>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Player.h";
#include "Laser.h";

using namespace std;
using namespace sf;

class Inputs
{
public:
	Inputs(Player& player, vector<RectangleShape>& lasers) : _player(player), _lasers(lasers) {};

	void HandleInputs();

private:
	Player& _player;
	Clock _clock;
	vector<RectangleShape>& _lasers;
};

