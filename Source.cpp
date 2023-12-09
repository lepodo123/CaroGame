#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
	int player=-1;
};

bool checkDuplicate(Point point, Point p[]) {
	for (int i = 0; i < 25; i++) {

		if (p[i].x == point.x && p[i].y == point.y) {
			if (p[i].player != -1) {
				return true;
			}
      		}
	}
	return false;
}


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

Point Input(int player) {
	Point p;
	
		cout << "Luot danh cua choi " << player;
		cout << "\nNhap dong(1-5): ";
		cin >> p.x;
		cout << "\nNhap cot(1-5): ";
		cin >> p.y;
		p.player = player % 2;

	return p;
}

bool checkWin(Point p[],Point point) {
		
	if (checkRow(point, p) || checkColumn(point, p) || checkDiagonal(point,p)) {
		return true;
	}
	return false;
}


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
void Handle() {
	Point p[25];
	DrawBoard(p);
	int player = 0;
	for (int i = 0; i < 25; i++) {
		player = i % 2;
		while(true){
			
			Point point;
			while (true)
			{
				point = Input(player);
				if (point.x > 0 && point.x < 6 && point.y> 0 && point.y < 6) {
					break;
				}
				DrawBoard(p);
			}
			if (checkDuplicate(point, p) == false) {
				p[i] = point;
				DrawBoard(p);
				break;
			}
			
			DrawBoard(p);
			cout << "Da co nguoi choi danh vao vi tri do.\nMoi danh lai." << endl;
		}
		
		if (checkWin(p, p[i])) {
			cout << "NGUOI CHOI " << player << " THANG.";
			if (i == 23) {
				i++;
			}
			break;
		}
	
		if (i == 24) {
			cout << "2 NGUOI CHOI HOA ";
		}
	}
}
int main() {
	Handle();
	cout << "\n";
	system("pause");
	return 0;
}