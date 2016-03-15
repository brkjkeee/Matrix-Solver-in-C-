#include <iostream>

using namespace std;

class matrix{
private:
	int marr[3][3];
	char name;

public:	
	matrix() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				marr[i][j] = 0;
			}
		}
		for (int i = 0; i < 3; i++)	marr[i][i] = 1;
	}
};