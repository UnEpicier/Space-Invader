#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player
{
public:
	Player(int screenSize);

	CircleShape getShape() { return _shape; };
	void move(int direction);

private:
	CircleShape _shape;

	int _screenSize;
};

