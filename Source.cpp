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
				if (point.x > 0 && point.x < 6 && point.y> 0 && point.y < 5) {
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
			break;
		}
	}
	
	
	
}
int main() {
	Handle();
	cout << "\n";
	system("pause");
	return 0;
}