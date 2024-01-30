using namespace std;

#include <iostream>

#include "GameManager.h"

int main()
{
	cout << "Starting game..." << endl;
	GameManager gameManager;

	cout << "Game started." << endl;
	gameManager.run();

	return 0;
}