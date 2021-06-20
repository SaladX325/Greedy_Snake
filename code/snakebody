#pragma once
#include "snakehead.h"
#include <vector>
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



typedef struct Body {
	int x, y;
	Body* next = NULL;
	Body* pre = NULL;
}Body, * s;

class snakebody
{
public:
	Body* head = new Body;
	Body* last = new Body;
	Body* s_end = new Body;
	snakebody() {}

	void initialize(snakehead shead) {
		head->x = shead.xval();
		head->y = shead.yval();
		switch (shead.dir()) {
		case up:
			last->x = shead.xval() + 1;
			last->y = shead.yval();
			s_end->x = shead.xval() + 2;
			s_end->y = shead.yval();
			break;
		case right:
			last->x = shead.xval();
			last->y = shead.yval() - 1;
			s_end->x = shead.xval();
			s_end->y = shead.yval() - 2;
			break;

		case down:
			last->x = shead.xval() - 1;
			last->y = shead.yval();
			s_end->x = shead.xval() - 2;
			s_end->y = shead.yval();
			break;

		case left:
			last->x = shead.xval();
			last->y = shead.yval() + 1;
			s_end->x = shead.xval();
			s_end->y = shead.yval() + 2;
			break;
		}
		
		head->next = last;
		last->pre = head;
		last->next = s_end;
		s_end->pre = last;
	}



	void move(snakehead shead) {
		Body* p = new Body;
		p->x = head->x;
		p->y = head->y;
		p->next = head->next;
		head->next->pre = p;
		head->x = shead.xval();
		head->y = shead.yval();
		head->next = p;
		p->pre = head;

		Body* q = new Body;
		q = s_end;
		s_end = s_end->pre;
		free(q);
		s_end->next = NULL;
	}

	void grow(snakehead shead) {
		Body* p = new Body;
		p->x = head->x;
		p->y = head->y;
		p->next = head->next;
		head->next->pre = p;
		head->x = shead.xval();
		head->y = shead.yval();
		head->next = p;
		p->pre = head;
	}



	void print() {
		Body* p = new Body;
		p = head->next;
		cout << "Body: " << endl;
		while (p) {
			cout << p->x << "\t" << p->y << endl;
			p = p->next;
		}
	}

	vector<pair<int, int>> output() {
		vector<pair<int, int>> x;
		Body* p = new Body;
		p = head->next;
		while (p) {
			x.push_back({ p->x, p->y });
			p = p->next;
		}
		return x;
	}
};

