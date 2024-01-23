#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Laser
{
public:
	Laser() {};
	Laser(Window& window);

	RectangleShape& getShape() { return _laser; }
	
	void setInitialPosition(Vector2f position);

private:
	RectangleShape _laser;
};

