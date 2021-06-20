#include <iostream>
#include <vector>
#include <conio.h>
#include "snakehead.h"
#include "snakebody.h"
#include "food.h"
#include "Gamemap.h"
#include <stdlib.h>
#define X 30
#define Y 100
#define up 72
#define down 80
#define right 77
#define left 75
int opp_dir[9] = { 80, 0, 0, 77, 0, 75, 0, 0, 72 };

using namespace std;

void food_generate(int x, int y, food* f) {
	srand((unsigned)clock() % 1000);
	f->x = rand() % x;
	f->y = rand() % y;
}
int input(int time, int dir) {
	int key = 0;
	int t = clock();
	int delta = 0;
	int i;
	while (delta < time) {
		delta = clock() - t;
		key = _kbhit();
		if (key) {
			_getch();
			i = _getch();
			if (i == left || i == right || i == up || i == down) {
				if (i != opp_dir[dir - 72]) {
					return i;
				}
			}
		}
	}
	return 0;
}

void ctrl(snakehead* shead, int level) {
	int time = 1000 / level;
	int key = input(time, shead->dir());
	if (key) {
		shead->dwrite(key);
	}
}

void print(Gamemap* gm, snakehead shead, snakebody sbody, food f) {
	system("cls");
	gm->gamearray = gm->basemap;
	gm->gamearray[f.x][f.y] = '*';
	gm->gamearray[shead.xval()][shead.yval()] = '@';
	vector<pair<int, int>> x;
	x = sbody.output();
	for (int i = 0; i < x.size(); i++) {
		gm->gamearray[x[i].first][x[i].second] = '+';
	}
	gm->print();
}

bool gameover(snakehead shead, snakebody sbody, Gamemap gm) {
	bool flag = 0;
	

	return flag;
}



void check() {

}

bool isgrow(snakehead shead, food f) {
	int mx = 0, my = 0;
	switch (shead.dir())
	{
	case up:
		mx = -1;
		my = 0;
		break;

	case down:
		mx = 1;
		my = 0;
		break;

	case left:
		mx = 0;
		my = 1;
		break;

	case right:
		mx = 0;
		my = -1;
		break;

	default:
		break;
	}
	if (f.x == shead.xval() + mx && f.y == shead.yval() + my) {
		return 1;
	}
	else return 0;
}

void move(snakehead* shead, snakebody* sbody) {
	shead->move();
	sbody->move(*shead);
	
}

void grow_and_move(snakehead* shead, snakebody* sbody) {
	shead->move();
	sbody->grow(*shead);
	//sbody->move(*shead);
}

void run(snakehead* shead, snakebody* sbody, Gamemap* gm, food f) {
	while (1) {
		ctrl(shead, 1);
		//check();
		int is_grow = isgrow(*shead, f);
		if (is_grow) {
			grow_and_move(shead, sbody);
			food_generate(X, Y, &f);
		}
		else move(shead, sbody);
		
		print(gm, *shead, *sbody, f);

	}
}



int main() {
	snakehead a = snakehead();
	snakebody b = snakebody();
	Gamemap gm = Gamemap();
	food f = food();
	food_generate(X, Y, &f);
	//f.generate(X,Y, clock() % 1000);
	a.dwrite(up);
	a.xwrite(9);
	a.ywrite(18);
	b.initialize(a);

	run(&a, &b, &gm, f);
	//while (1) {

	//}
	return 0;


}


