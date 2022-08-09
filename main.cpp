#include<iostream>
#include<vector>
#include<memory>
#include<algorithm>
#include<list>
#include<map>
#include<easyx.h>
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
class node
{
public:
	double x;
	double y;
	node(double x, double y)
	{
		this->x = x;
		this->y = y;
	}


};
void creatfood()
{
	int positionx = (rand() % 600 / 18) * 18;
	int positiony = (rand() % 600 / 18) * 18;
	fillrectangle(positionx, positiony, positionx + 18, positiony + 18);
}
int _tmain(int argc, char* argv[])
{
	srand(time(nullptr));

	list<node>snack;
	snack.push_back(node(9, 9));
	initgraph(600, 600, EW_SHOWCONSOLE);//可显示出两块屏幕
	int flag = 0;
	setbkcolor(BLACK);
	cleardevice();
	while (1)
	{
		if (flag == 0)
		{
			creatfood();
			flag = 1;

		}
		if (_kbhit())
		{
			char direction = _getch();
			list<node>::iterator head = snack.begin();
			switch (direction)
			{
			case 'a': clearrectangle(head->x - 9, head->y - 9, head->x + 9, head->y + 9); head->x -= 18;  break;
			case 's':clearrectangle(head->x - 9, head->y - 9, head->x + 9, head->y + 9); head->y += 18;  break;
			case 'd':clearrectangle(head->x - 9, head->y - 9, head->x + 9, head->y + 9); head->x += 18;  break;
			case 'w':clearrectangle(head->x - 9, head->y - 9, head->x + 9, head->y + 9); head->y -= 18;  break;
			default:
				break;
			}
		}


		for (list<node>::iterator it = snack.begin(); it != snack.end(); ++it)
		{
			fillrectangle(it->x - 9, it->y - 9, it->x + 9, it->y + 9);

		}
	}
	/*	system("pause");*/
}
