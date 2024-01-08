#include "Inputs.h"

void Inputs::HandleInputs(Event& event) {
	if (event.type == Event::Closed)
	{
		_window.close();
		return;
	}

	// Player movements
	if (event.type == Event::KeyPressed) {
		if (event.key.code == Keyboard::Left || event.key.code == Keyboard::Q) {
			_player.Move(-1);
		}
		if (event.key.code == Keyboard::Right || event.key.code == Keyboard::D) {
			_player.Move(1);
		}
	}
}