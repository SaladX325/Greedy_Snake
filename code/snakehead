#pragma once
#include <iostream>
#define up 72
#define down 80
#define right 77
#define left 75

using namespace std;

/***
* Direction:
*		72
*		|
*		|
* 75----head----77
*		|
*		|
*		80
***/
class snakehead
{
private:
	int direction, x, y;
public:
	snakehead(int d = 0, int xx = 0, int yy = 0) : direction(d), x(xx), y(yy) {}
	int xval() const { return	x; }
	int yval() const { return	y; }
	int dir() const { return	direction; }
	void xwrite(int a) { x = a; }
	void ywrite(int a) { y = a; }
	void move() { 
		switch (direction) {
		case up:
			x--;
			break;
		case down:
			x++;
			break;
		case right:
			y++;
			break;
		case 75:
			y--;
			break;
		}
	}
	void dwrite(int a) { direction = a; }
	void print() {
		cout << "Head: \n" << x << "\t" << y << endl;
	}


};

