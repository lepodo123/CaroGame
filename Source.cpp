#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
	int player=-1;
};
bool checkRow(Point point, Point p[]) {
	if (point.x == 3 && point.player != -1) {
			for (int i = 0; i < 25; i++) {
				if (p[i].x == point.x - 1 && p[i].player == point.player && p[i].y==point.y) {
					for (int j = 0; j < 25; j++) {
						if (p[j].x == point.x - 2 && p[j].player == point.player && p[i].y == point.y) {
							return true;
						}
						else if (p[j].x == point.x + 1 && p[j].player == point.player && p[i].y == point.y) {
							return true;
						}
					}
					
				}
				else if (p[i].x == point.x +1 && p[i].player == point.player && p[i].y == point.y) {
					for (int j = 0; j < 25; j++) {
						if (p[j].x == point.x + 2 && p[j].player == point.player && p[i].y == point.y) {
							return true;
						}
					}
				}
			
		}
	}
	else if (point.x <3 && point.player!=-1){
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x - 1 && p[i].player == point.player && p[i].y == point.y) {
				for (int j = 0; j < 25; j++) {
					if (p[j].x == point.x + 1 && p[j].player == point.player && p[i].y == point.y) {
						return true;
					}
				}

			}
			else if (p[i].x == point.x + 1 && p[i].player == point.player && p[i].y == point.y) {
				for (int j = 0; j < 25; j++) {
					if (p[j].x == point.x + 2 && p[j].player == point.player && p[i].y == point.y) {
						return true;
					}
				}
			}

		}
	}
	else if (point.x > 3 && point.player != -1){
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x - 1 && p[i].player == point.player) {
				for (int j = 0; j < 25; j++) {
					if (p[j].x == point.x - 2 && p[j].player == point.player) {
						return true;
					}
					else if (p[j].x == point.x + 1 && p[j].player == point.player) {
						return true;
					}
				}

			}
		}
	}
	
	return false;
}
bool checkColumn(Point point, Point p[]) {
	if (point.y == 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].y == point.y - 1 && p[i].player == point.player && p[i].x==point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y - 2 && p[j].player == point.player && p[i].x == point.x) {
						return true;
					}
					else if (p[j].y == point.y + 1 && p[j].player == point.player && p[i].x == point.x) {
						return true;
					}
				}

			}
			else if (p[i].y == point.y + 1 && p[i].player == point.player && p[i].x == point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y + 2 && p[j].player == point.player && p[i].x == point.x) {
						return true;
					}
				}
			}

		}
	}
	else if (point.y < 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].y == point.y - 1 && p[i].player == point.player && p[i].x == point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y + 1 && p[j].player == point.player && p[i].x == point.x) {
						return true;
					}
				}

			}
			else if (p[i].x == point.y + 1 && p[i].player == point.player && p[i].x == point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y + 2 && p[j].player == point.player && p[i].x == point.x) {
						return true;
					}
				}
			}

		}
	}
	else if(point.y>3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].y == point.y - 1 && p[i].player == point.player && p[i].x == point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y - 2 && p[j].player == point.player && p[i].x == point.x) {
						return true;
					}
					else if (p[j].y == point.y + 1 && p[j].player == point.player && p[i].x == point.x
						) {
						return true;
					}
				}

			}
		}
	}
	return false;
}

int main() {
	Handle();
	cout << "\n";
	system("pause");
	return 0;
}