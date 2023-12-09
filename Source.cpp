#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
	int player=-1;
};

void DrawBoard(Point p[],int size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			cout << "\n";
			for (int z = 0; z < size+1; z++) {
				if (z == 0) {
					cout << "      |";
				}
				else {
					cout << "  " << z << "   |";
				}
			}
			cout << "\n";
			for (int z = 0; z < size; z++) {
				cout << "----------";
			}
			
		}
		cout << "\n";
		for (int j = 0; j < size+1; j++) {
			if (j == 0) {
				cout << "  " << i + 1 << "   |";
			}
			else {
				char c = ' ';
				for (int l = 0; l < 25; l++) {

					if (p[l].x == i + 1 && p[l].y == j) {

						if (p[l].player == 0) {
							c = 'X';
						}
						else {
							c = 'O';
						}
					}
				}
				cout << "  " << c << "   |";
			}
		}
		cout << "\n";
		for (int z = 0; z < size; z++) {
			cout << "----------";
		}
	}
	cout << "\n";
}

int main() {
	Handle();
	cout << "\n";
	system("pause");
	return 0;
}