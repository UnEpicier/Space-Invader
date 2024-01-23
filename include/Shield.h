#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Shield
{
public:
	Shield() {};
	Shield(Window& window);

	void setPosition(Vector2f position);

	RectangleShape& getShape() { return _shape; };

	int getLife() const { return _life; };
	void decreaseLife() { _life -= 1; };

private:
	int _life = 10;
	RectangleShape _shape;
};