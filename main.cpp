#include "main.h";

int main()
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Space Invader", Style::Titlebar | Style::Close);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	Player player(window);
	Inputs inputs(window, player);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			inputs.HandleInputs(event);

			window.clear(Color::Black);

			player.DrawPlayer();

			window.display();
		}
	}

	return 0;
}