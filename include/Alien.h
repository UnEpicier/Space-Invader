#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Alien
{
public:
	Alien(Vector2f& position);

	RectangleShape& getShape() { return _shape; };

private:
	RectangleShape _shape;
};