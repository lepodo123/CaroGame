#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

struct Point {
	int x;
	int y;
	int player = -1;
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
              >>>>>>> developer
							c = 'O';
						}
					}
				}				cout << "  " << c << "   |";
			}
		}
		cout << "\n";
		for (int z = 0; z < size; z++) {
			cout << "----------";
		}
        >>>>>>> developer
	}
	cout << "\n";
}
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

bool checkRow(Point point, Point p[]) {
	if (point.x == 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x - 1 && p[i].player == point.player && p[i].y == point.y) {
				for (int j = 0; j < 25; j++) {
					if (p[j].x == point.x - 2 && p[j].player == point.player && p[j].y == point.y) {
						return true;
					}
					else if (p[j].x == point.x + 1 && p[j].player == point.player && p[j].y == point.y) {
						return true;
					}
				}

			}
			else if (p[i].x == point.x + 1 && p[i].player == point.player && p[i].y == point.y) {
				for (int j = 0; j < 25; j++) {
					if (p[j].x == point.x + 2 && p[j].player == point.player && p[j].y == point.y) {
						return true;
					}
				}
			}

		}
	}
	else if (point.x < 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x - 1 && p[i].player == point.player && p[i].y == point.y) {
				for (int j = 0; j < 25; j++) {
					if (p[j].x == point.x + 1 && p[j].player == point.player && p[j].y == point.y) {
						return true;
					}
				}

			}
			else if (p[i].x == point.x + 1 && p[i].player == point.player && p[i].y == point.y) {
				for (int j = 0; j < 25; j++) {
					if (p[j].x == point.x + 2 && p[j].player == point.player && p[j].y == point.y) {
						return true;
					}
				}
			}

		}
	}
	else if (point.x > 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].x == point.x - 1 && p[i].player == point.player && p[i].y == point.y) {
				for (int j = 0; j < 25; j++) {
					if (p[j].x == point.x - 2 && p[j].player == point.player && p[j].y == point.y) {
						return true;
					}
					else if (p[j].x == point.x + 1 && p[j].player == point.player && p[j].y == point.y) {
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
			if (p[i].y == point.y - 1 && p[i].player == point.player && p[i].x == point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y - 2 && p[j].player == point.player && p[j].x == point.x) {
						return true;
					}
					else if (p[j].y == point.y + 1 && p[j].player == point.player && p[j].x == point.x) {
						return true;
					}
				}

			}
			else if (p[i].y == point.y + 1 && p[i].player == point.player && p[i].x == point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y + 2 && p[j].player == point.player && p[j].x == point.x) {
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
					if (p[j].y == point.y + 1 && p[j].player == point.player && p[j].x == point.x) {
						return true;
					}
				}

			}
			else if (p[i].x == point.y + 1 && p[i].player == point.player && p[i].x == point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y + 2 && p[j].player == point.player && p[j].x == point.x) {
						return true;
					}
				}
			}

		}
	}
	else if (point.y > 3 && point.player != -1) {
		for (int i = 0; i < 25; i++) {
			if (p[i].y == point.y - 1 && p[i].player == point.player && p[i].x == point.x) {
				for (int j = 0; j < 25; j++) {
					if (p[j].y == point.y - 2 && p[j].player == point.player && p[j].x == point.x) {
						return true;
					}
					else if (p[j].y == point.y + 1 && p[j].player == point.player && p[j].x == point.x
						) {
						return true;
					}
				}

			}
		}
	}
	return false;
}
bool checkDiagonal(Point point, Point p[]) {
	for (int i = 0; i < 25; i++) {

		if (p[i].x == point.x - 1 && p[i].y == point.y - 1 && point.player == p[i].player) {

			for (int j = 0; j < 25; j++) {
				if (p[j].x == point.x + 1 && p[j].y == point.y + 1 && point.player == p[j].player) {
					return true;
				}
				else if (p[j].x == point.x - 2 && p[j].y == point.y - 2 && point.player == p[j].player) {
					return true;
				}
			}
		}
		if (p[i].x == point.x - 1 && p[i].y == point.y + 1 && point.player == p[i].player) {
			for (int j = 0; j < 25; j++) {
				if (p[j].x == point.x - 2 && p[j].y == point.y + 2 && point.player == p[j].player) {
					return true;
				}
				else if (p[j].x == point.x + 1 && p[j].y == point.y - 1 && point.player == p[j].player) {
					return true;
				}
			}
		}
		if (p[i].x == point.x + 1 && p[i].y == point.y - 1 && point.player == p[i].player) {

			for (int j = 0; j < 25; j++) {
				if (p[j].x == point.x + 2 && p[j].y == point.y - 2 && point.player == p[j].player) {
					return true;
				}
				else if (p[j].x == point.x - 1 && p[j].y == point.y + 1 && point.player == p[j].player) {
					return true;
				}
			}
		}
		if (p[i].x == point.x + 1 && p[i].y == point.y + 1 && point.player == p[i].player) {

			for (int j = 0; j < 25; j++) {
				if (p[j].x == point.x + 2 && p[j].y == point.y + 2 && point.player == p[j].player) {
					return true;
				}
				else if (p[j].x == point.x - 1 && p[j].y == point.y - 1 && point.player == p[j].player) {
					return true;
				}
			}
		}
	}
	return false;
}

Point Input(int player, int size) {
	
	Point p;
	cout << "Luot danh cua choi " << player;
	cout << "\nNhap dong(1-" << size << "): ";
	cin >> p.x;
	cout << "\nNhap cot(1-" << size << "): ";
	cin >> p.y;
	p.player = player;
	return p;
}

bool checkWin(Point p[], Point point) {

	if (checkRow(point, p) || checkColumn(point, p) || checkDiagonal(point, p)) {
		return true;
	}
	return false;
}
bool Handle(Point p[], int size)
{

	DrawBoard(p, size);
	int player = 0;
	int timepturn = 45;

	for (int i = 0; i < size * size; i++)
	{
		player = i % 2;
		while (true)
		{
			Point point;

			while (true)
			{
				point = Input(player, size);
				if (point.x > 0 && point.x <= size && point.y > 0 && point.y <= size)
				{
					break;
				}
				DrawBoard(p, size);
			}
			if (checkDuplicate(point, p) == false)
			{
				p[i] = point;
				DrawBoard(p, size);
				break;
			}

			DrawBoard(p, size);
			cout << "Da co nguoi choi danh vao vi tri do.\nMoi danh lai." << endl;
		}

		if (checkWin(p, p[i]))
		{
			cout << "NGUOI CHOI " << player << " THANG.";
			return true;
		}
		if (i == size * size - 1)
		{
			cout << "2 NGUOI CHOI HOA ";
		}
	}
	return false;
}
int main() {
	int size;
	Point p[10];
	cout << "Nhap kich thuoc ban co: ";
	cin >> size;
	p[size];
	if (Handle(p, size)==false) {
		cout << "\nBan co muon mo rong ban co. Neu muon hay nhap kich thuoc (nhap -1 de thoat): ";
		cin >> size;
		if (size > 0) {
			Handle(p, size);
		}
	}
	cout << "\n";
	system("pause");
	return 0;
}
