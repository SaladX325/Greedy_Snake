#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Gamemap
{
	enum {
		x = 30, y = 100 //x is rows, y is columns
	};
public:
	vector<string> gamearray;
	vector<string> basemap;
	Gamemap() : gamearray(), basemap() {
		string tempstr = "";
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				if ((i == 0 || i == x - 1) && (j == 0 || j == y - 1)) {
					tempstr += '+';
				}
				else if (i == 0 || i == x - 1) {
					tempstr += '-';
				}
				else if (j == 0 || j == y - 1) {
					tempstr += '|';
				}
				else {
					tempstr += ' ';
				}

			}
			gamearray.push_back(tempstr);
			basemap.push_back(tempstr);
			tempstr = "";
		}
	}

	void print() {
		for (int i = 0; i < x; i++) {
			cout << gamearray[i];
			cout << endl;
		}
	}
};

