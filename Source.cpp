#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
	int player=-1;
};
bool checkDiagonal(Point point, Point p[]) {
	if (point.x == 3 && point.y == 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x - 1 && p[i].y == point.y - 1 && point.player == p[i].player) {
				if (p[i].x == point.x+1 && p[i].y == point.y+1&& point.player == p[i].player) {
					return true;
				}
			}
			else if (p[i].x == point.x - 1 && p[i].y+1 == point.y && point.player == p[i].player) {
				if (p[i].x == point.x + 1 && p[i].y - 1 == point.y && point.player == p[i].player) {
					return true;
				}
			}
		}
	}
	else if (point.x < 3 && point.y < 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x + 1 && p[i].y == point.y + 1 && point.player == p[i].player) {
				if (p[i].x == point.x + 2 && p[i].y == point.y + 2 && point.player == p[i].player) {
					return true;
				}
			}
		}
	}
	else if (point.x > 3 && point.y > 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x -1  && p[i].y == point.y - 1 && point.player == p[i].player) {
				if (p[i].x == point.x - 2 && p[i].y == point.y - 2 && point.player == p[i].player) {
					return true;
				}
			}
		}
	}
	else if (point.x < 3 && point.y > 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x + 1 && p[i].y == point.y - 1 && point.player == p[i].player) {
				if (p[i].x == point.x + 2 && p[i].y == point.y - 2 && point.player == p[i].player) {
					return true;
				}
			}
		}

	}
	else if (point.x > 3 && point.y < 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x - 1 && p[i].y == point.y + 1 && point.player == p[i].player) {
				if (p[i].x == point.x - 2 && p[i].y == point.y + 2 && point.player == p[i].player) {
					return true;
				}
			}
		}

	}
	else if (point.x == 3 && point.y == 1 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x + 1 && p[i].y == point.y - 1 && point.player == p[i].player) {
				if (p[i].x == point.x + 2 && p[i].y == point.y - 2 && point.player == p[i].player) {
					return true;
				}
			}
			else if (p[i].x == point.x + 1 && p[i].y == point.y + 1 && point.player == p[i].player) {
				if (p[i].x == point.x + 2 && p[i].y == point.y + 2 && point.player == p[i].player) {
					return true;
				}
			}
		}
	}
	else if (point.x == 3 && point.y == 5 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x - 1 && p[i].y == point.y - 1 && point.player == p[i].player) {
				if (p[i].x == point.x - 2 && p[i].y == point.y - 2 && point.player == p[i].player) {
					return true;
				}
			}
			else if (p[i].x == point.x + 1 && p[i].y == point.y - 1 && point.player == p[i].player) {
				if (p[i].x == point.x + 2 && p[i].y == point.y - 2 && point.player == p[i].player) {
					return true;
				}
			}
		}
	}
	return false;
}
bool checkWin(Point p[],Point point) {
		
	if (checkRow(point, p) || checkColumn(point, p) || checkDiagonal(point,p)) {
		return true;
	}
	return false;
}
int main() {
	Handle();
	cout << "\n";
	system("pause");
	return 0;
}