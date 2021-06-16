#include <iostream>
#include <conio.h>
#include "snakehead.h"
#include "snakebody.h"
#include "food.h"
#include "Gamemap.h"
#define X 30
#define Y 100

using namespace std;

int input() {
	int i;
	int j;
	j = _getch();
	i = _getch();
	cout << i << endl;
	return i;
}

void combine(Gamemap* gm, snakehead shead, snakebody sbody) {
	gm->gamearray[shead.xval()][shead.yval()] = '@';
	Body *p = new Body;
	p = sbody.head->next;
	while (p) {
		gm->gamearray[p->x][p->y] = '+';
		p = p->next;
	}
}




void Present(snakehead shead, snakebody sbody, Gamemap gm, food f) {

}




bool gameover(snakehead shead, snakebody sbody, Gamemap gm) {
	bool flag = 0;
	

	return flag;
}


void move(snakehead* shead, snakebody* sbody) {
	shead->move();
	sbody->move(*shead);
	
}

void grow_and_move(snakehead* shead, snakebody* sbody) {
	sbody->grow(*shead);
	shead->move();
	sbody->move(*shead);
}

void run(snakehead shead, snakebody sbody, Gamemap gm) {
	while (1) {

	}
}



int main() {
	snakehead a = snakehead();
	snakebody b = snakebody();
	a.dwrite(1);
	a.xwrite(9);
	a.ywrite(18);
	a.move();
	a.print();
	b.initialize(a);
	move(&a, &b);
	a.print();
	b.print();
	Gamemap gm = Gamemap();
	gm.initialize();
	//combine(&gm, a, b);
	gm.print();



	return 0;


}


