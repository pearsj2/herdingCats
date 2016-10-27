//Author: Jessica Pearson
//

#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GreedyRobot
{

public:
	GreedyRobot();
	GreedyRobot(string robotName, int startX, int startY, int endX, int endY);
	GreedyRobot(int startX, int startY, int endX, int endY);

	void greedyRobotStart(int x,int y);
	void treasureStart(int x,int y);
	void treasureHunt();
	~GreedyRobot();


private:
	string robotName;
	int positionX;
	int positionY;
	int treasureX;
	int treasureY;
	int pathCount;

	//void Robot(int x, int y);
	//void Treasure(int x, int y);

	void treasureHunt(const string passedPath,const int& startX,const int& startY, int& paths);
		
	vector<string> mapPath;
	


};


