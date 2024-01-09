#include "main.h";

int main()
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Invader", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	Player player(window);
	vector<RectangleShape> lasers;

	Inputs inputs(player, lasers);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		// Handle user's inputs
		inputs.HandleInputs();

		window.clear(Color::Black);

		// Draw everything
		player.drawPlayer();

		for (vector<RectangleShape>::iterator it = lasers.begin(); it < lasers.end();) {
			window.draw(*it);
			it->move(0, -5);

			if (it->getPosition().y < -it->getScale().y) {
				it = lasers.erase(it);
			}
			else {
				lasers[distance(lasers.begin(), it)] = *it;
				++it;
			}
		}

		// Display window
		window.display();
	}

	return 0;
}