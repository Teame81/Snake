#include <iostream>
#include <Windows.h>
#include <conio.h>
//#include <stdlib.h>


using namespace std;

bool gameOver{};
const int width = 20;
const int height = 20;
const int maxSnakeSize = width * height - (width + height * 2 - 1);// tail size is width time height - walls and minus 1 for the head
int playerX{}, playerY{}, mouseX{}, mouseY{}, score{}, tailX[maxSnakeSize], tailY[maxSnakeSize], nTail{};


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
				bool printtail = false;

				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						printtail = true;
					}
				}
				if (!printtail)
				{
					cout << " ";
				}
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
	int previousXtail = tailX[0];
	int previousYtail = tailY[0];
	int previousXtail2, previousYtail2;
	tailX[0] = playerX;
	tailY[0] = playerY;

	for (int i = 1; i < nTail; i++)
	{
		previousXtail2 = tailX[i];
		previousYtail2 = tailY[i];
		tailX[i] = previousXtail;
		tailY[i] = previousYtail;
		previousXtail = previousXtail2;
		previousYtail = previousYtail2;

	}



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
	if (playerX >= width - 1)
	{
		playerX = 1;
	}
	else if (playerX < 1)
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
		nTail++;
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
