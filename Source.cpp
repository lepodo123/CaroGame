#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

struct Point {
	int x;
	int y;
	int player = -1;
};


void DrawBoard(Point p[], int size) {
	system("cls");
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			cout << "\n";
			for (int z = 0; z < size + 1; z++) {
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
		for (int j = 0; j < size + 1; j++) {
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
				}				cout << "  " << c << "   |";
			}
		}
		cout << "\n";
		for (int z = 0; z < size; z++) {
			cout << "----------";
		}
	}
	cout << "\n";
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

bool Handle(Point p[], int size, int oldsize)
{

	DrawBoard(p, size);
	int player = 0;
	int timepturn = 45;
	cout << oldsize;
	cout << size;
	for (int i = oldsize; i < size * size; i++)
	{

		player = i % 2;
		while (true)
		{
			Point point;

			while (true)
			{
				point = Input(player, size);
				if (point.x == -1 || point.y == -1) {
					cout << "NGUOI CHOI " << (player + 1) % 2 << " THANG.";
					return true;
				}
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
			return false;
		}
	}
	return false;
}
int main() {
	int size;
	int oldsize = 0;
	Point p[100];
	cout << "Nhap kich thuoc ban co: ";
	cin >> size;
	p[size];
	bool win = Handle(p, size, oldsize);
	while (win != true) {
		oldsize = size * size;
		cout << "\nBan co muon mo rong ban co. Neu muon hay nhap kich thuoc (nhap -1 de thoat): ";
		cin >> size;

		if (size > 0) {
			win = Handle(p, size, oldsize);
		}

		cout << "\n";
	}
	system("pause");
	return 0;
}
