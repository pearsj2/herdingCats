// GreedyRobot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GreedyRobot.h"
//Author: Jessica Pearson
//This program was created as part of a school assignment to understand a greedy algorithm
//The assignmnet was meant to introduce greedy algorithms, the name of the school and assignmnet
//have been removed for confidentiality purposes.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//default contructor
GreedyRobot::GreedyRobot()
{
	this->robotName = "LondonCalling";
	this->positionX = 0;
	this->positionY = 0;
	this->treasureX = 0;
	this->treasureY = 0;
}

//Overloaded constructor 1
GreedyRobot::GreedyRobot(string robotName, int startX, int startY, int endX, int endY)
{
	this->robotName = robotName;
	this->positionX = startX;
	this->positionY = startY;
	this->treasureX = endX;
	this->treasureY = endY;
}

//Overloaded Constructor 2
GreedyRobot::GreedyRobot(int startX, int startY, int endX, int endY)
{
	this->robotName = "theCasbah";
	this->positionX = startX;
	this->positionY = startY;
	this->treasureX = endX;
	this->treasureY = endY;
}

//Set a starting position for the robot on the grid
void GreedyRobot::greedyRobotStart(int x, int y)
{
	this-> positionX = x;
	this-> positionY = y;
}

//Set a position fo rthe treasure to reside on the grid
void GreedyRobot::treasureStart(int x, int y)
{
	this-> treasureX = x;
	this-> treasureY = y;

}


void GreedyRobot::treasureHunt()
{
	string path = "";
	int paths = 0;
	treasureHunt(path, positionX, positionY, paths);
	cout << "Number of paths: " << paths << endl;
}

//The treasure hunt method recursively travels the grid looking for the treasure
void GreedyRobot::treasureHunt(const string passedPath, const int& botX, const int& botY, int& paths)
{
	string path;
	int tempX = botX;
	int tempY = botY;

	if (tempX == this->treasureX && tempY == this->treasureY)
	{
		cout << passedPath << endl;
		pathCount++;
		paths++;
	}

	else
	{
		if (tempY < this->treasureY)
		{
			path = passedPath;
			path.append("N");
			treasureHunt(path, tempX, tempY + 1, paths);
		}
		if (tempY > this->treasureY)
		{
			path = passedPath;
			path.append("S");
			treasureHunt(path, tempX, tempY - 1, paths);
		}
		if (tempX < this->treasureX)
		{
			path = passedPath;
			path.append("E");
			treasureHunt(path, tempX + 1, tempY, paths);
		}
		if (tempX > this->treasureX)
		{
			path = passedPath;
			path.append("W");
			treasureHunt(path, tempX - 1, tempY, paths);
		}
	}
}
GreedyRobot::~GreedyRobot()
{

}