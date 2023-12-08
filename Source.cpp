#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
	int player=-1;
};

void DrawBoard(Point p[]) {
	system("cls");
			for (int i = 0; i < 5; i++) {
			if (i == 0) {
				cout << "\n";
				for (int z = 0; z < 6; z++) {
					if (z == 0) {
						cout << "     |";
					}
					else {
						cout << "  " << z << "  |";
					}
				}
				cout << "\n------------------------------------";
			}
			cout << "\n";
			for (int j = 0; j < 6; j++) {
				if (j == 0) {
					cout << "  " << i+1 << "  |";
				}
				else {
					char c = ' ';
					for (int l = 0; l < 25; l++) {
						
						if (p[l].x == i+1 && p[l].y==j) {
							
							if (p[l].player == 0) {
								c = 'X';
							}
							else {
								c = 'O';
							}
						}		
					}
					cout <<"  " << c << "  |";
				}
			}
			cout << "\n------------------------------------";
	}
	cout << "\n";
}

int main() {
	Handle();
	cout << "\n";
	system("pause");
	return 0;
}