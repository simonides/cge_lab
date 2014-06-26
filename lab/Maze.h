#pragma once
#include <vector>
#include <functional>

using namespace std;

class Maze
{
private:
	char * path;
	vector<vector<char> *> * maze;

	int width;
	int height;

	bool parsed;

public:
	Maze(char * path);

	void parse();
	char at(int x, int y);

	void walk(function<void(int, int)> boxCallback, function<void(int, int)> pathCallback);

	int getWidth();
	int getHeight();

	virtual ~Maze();
};

