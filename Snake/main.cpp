#include <iostream>
#include <Windows.h>
#include <conio.h>
//#include <stdlib.h>


using namespace std;

bool gameOver{};
const int width = 20;
const int height = 20;
int playerX{}, playerY{}, mouseX{}, mouseY{}, score{};

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
		Sleep(100);
	}

	cin.get();
	return 0;
}

void Settings() {
	gameOver = false;
	direction = STOP;
	playerX = width / 2;
	playerY = height / 2;
	mouseX = rand() % width;
	mouseY = rand() % height;
	score = 0;
}

void Visual()
{
	system("cls");
	for (int i = 0; i < width; i++)
	{
		cout << "_";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == playerY && j == playerX)
			{
				cout << "O";
			}else if (i == mouseY && j == mouseX)
			{
				cout << "&";
			}else if (j == 0 || j == width - 1)
			{
				cout << "|";

			}
			else
			{
				cout << " ";
			}

		}
		cout << endl;
		
	}
	for (int i = 0; i < width; i++)
	{
		cout << "-";
	}
	cout << endl <<"Score: " << score;


}
void Logic()
{
	switch (direction)
	{
	case STOP:
		break;
	case LEFT:
		playerX--;
		break;
	case RIGHT:
		playerX++;
		break;
	case UP:
		playerY--;
		break;
	case DOWN:
		playerY++;
		break;
	default:
		break;
	}
	// Wall handeling
	if (playerX >= width)
	{
		playerX = 0;
	}
	else if (playerX < 0)
	{
		playerX = width - 1;
	}

	if (playerY >= height)
	{
		playerY = 0;
	}
	else if (playerY < 0)
	{
		playerY = height - 1;
	}


	// Is mouse eaten check
	if (playerX == mouseX && playerY == mouseY)
	{
		score++;
		mouseX = rand() % width;
		mouseY = rand() % height;
	}

}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w' :
				direction = UP;
				break;
		case 's':
			direction = DOWN;
			break;
		case 'a':
			direction = LEFT;
			break;
		case 'd':
			direction = RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		default:
			break;
		}

	}
}
