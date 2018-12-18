#include <iostream>

using namespace std;

bool gameOver{};
const int width = 20;
const int height = 20;
int x{}, y{}, mouseX{}, mouseY{}, score{};

enum eDirection
{	STOP,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

eDirection direction;

void Settings();
void Visual();
void Logic();
void Input();




int main() {
	
	Settings();

	while (!gameOver)
	{
		Visual();
		Input();
		Logic();
	}

	cin.get();
	return 0;
}

void Settings() {
	gameOver = false;
	direction = STOP;
	x = width / 2;
	y = height / 2;
	mouseX = rand() % width;
	mouseY = rand() % height;
	score = 0;
}

void Visual()
{
}
void Logic()
{
}

void Input()
{
}
