#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player
{
public:
	Player(RenderWindow& window): _window(window) {}

	CircleShape PlayerShape = CircleShape(20, 3);

	void DrawPlayer();
	void Move(int direction);

private:
	int _x = 0;
	int _velocity = 7;
	RenderWindow& _window;
};

