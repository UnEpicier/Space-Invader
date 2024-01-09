#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Laser
{
public:
	Laser();

	RectangleShape getLaser() { return _laser; }
	
	void setInitialPosition(Vector2f position);

private:
	RectangleShape _laser;
};

