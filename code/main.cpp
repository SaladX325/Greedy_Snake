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
	do {
		f->x = rand() % (x - 1);
		f->y = rand() % (y - 1);
	} while (f->x == 0 || f->y == 0);
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
	int time = 1200 / level;
	int key = input(time, shead->dir());
	if (key) {
		shead->dwrite(key);
	}
}
pair<int, int> nextstep(snakehead shead) {
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

	case right:
		mx = 0;
		my = 1;
		break;

	case left:
		mx = 0;
		my = -1;
		break;

	default:
		break;
	}
	return { shead.xval() + mx ,shead.yval() + my };
}



void check(Gamemap* gm, snakehead shead, snakebody sbody, food f, pair<int, int> step, int* is_grow, int* is_over) {

	gm->gamearray = gm->basemap;
	int sx = step.first;
	int sy = step.second;
	if (sx <= -1 || sx >= X || sy >= Y || sy <= -1) {
		*is_over = 1;
	}

	vector<pair<int, int>> x;
	x = sbody.output();
	int xb, yb;

	gm->gamearray[f.x][f.y] = '*';
	gm->gamearray[shead.xval()][shead.yval()] = '@';

	for (int i = 0; i < x.size(); i++) {
		xb = x[i].first; // x of body
		yb = x[i].second; // y of body

		if (sx == xb && sy == yb) *is_over = 1;
		gm->gamearray[xb][yb] = '+';
	}
	if (sx == f.x && sy == f.y) *is_grow = 1;
}

void gameover(int score) {
	system("cls");
	cout << "Game Over!" << endl;
	cout << "The score is: " << score << endl;
	cout << "Good Luck next time" << endl;
	cout << "Press SPACE to exit" << endl;
	int key = 0;
	while (key != 32) {
		key = _getch();
	}
	
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

void run(snakehead* shead, snakebody* sbody, Gamemap* gm, food f, int* score, int* level) {
	while (1) {
		*level = *score / 7 + 1;
		ctrl(shead, *level);
		int is_grow = 0;
		int is_over = 0;
		pair<int, int> step = nextstep(*shead);
		check(gm, *shead, *sbody, f, step, &is_grow, &is_over);
		system("cls");
		gm->print();
		cout << "Score: " << *score << endl;
		if (is_over) { gameover(*score); break; }
		if (is_grow) {
			grow_and_move(shead, sbody);
			food_generate(X, Y, &f);
			*score = *score + 1;
		}
		else move(shead, sbody);

	}
}



int main() {
	snakehead a = snakehead();
	snakebody b = snakebody();
	Gamemap gm = Gamemap();
	food f = food();
	food_generate(X, Y, &f);
	a.dwrite(down);
	a.xwrite(10);
	a.ywrite(10);
	b.initialize(a);
	int score = 0;
	int level = 1;

	run(&a, &b, &gm, f, &score, &level);

	return 0;


}


