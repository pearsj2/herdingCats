#include "stdafx.h"
#include "GreedyRobot.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int X1;
int X2;
int Y1;
int Y2;
int pathnum;

int main()
{

	int exit = 1;
	GreedyRobot sandinista;

	while (exit != 0)
	{
		cout << "Give your robot a starting location on the X axis, Y axis, and the treasure an X axis and Y axis as four integers: " << endl;
		cin >> X1; 
		//cout << "Give your robot a starting location on the Y axis: " << endl;
		cin >> Y1;

		//cout << "Give your treasure a starting location on the X axis: " << endl;
		cin >> X2;
		//cout << "Give your treasure a starting location on the Y axis: " << endl;
		cin >> Y2;

		sandinista.greedyRobotStart(X1, Y1);
		sandinista.treasureStart(X2, Y2);
		sandinista.treasureHunt();

		cout << "Press 0 to exit, 1 to play again: " << endl;
		cin >> exit;
	}
	return 0;
}