#include <iostream>
#include "TTT_Head.h"

using namespace std;

class TTT_Engine{
	private :
	int ground[3][3];	// '������' (0 - ���� / 1 - X / 2 - O)
	bool isInput[3][3]; // ground�� ���� �� / ���� �ֳ� ���� �Ǵ� (true = ������� / false = �� ����)
	int place[9][2]; // ������ �ִ� �ڸ��� ���� ��. <- �ִ� 9��.

	int level = 3; // ���̵�. �⺻ 3 (Ahead ���� ȸ��)

	void initall(); // �ʱ�ȭ �Լ�
	void init_place(); // ���� �� �ʱ�ȭ �Լ�.
	int place_trace(); // place�� �� ĭ ã���ִ� �Լ�.

	void Evaluate(); // Evaluate (����ȭ) �Լ�
	void Ahead(int level); // '���ٺ���' �Լ�
	void input_pin(int x,int y); // '�� �ø���'
	//void isWin(int pin); // ��� �ǵ� <- ������ private�� �� ��������.

	public :

	bool isFirst=true; // ��,�İ�
	int axis[2]; // 0 - x��, 1 - y��


	//�ܺ� ��Ʈ�� �κ�
	bool selectFirst(); // ���İ� ����
	void input_select(); // ����
	void selectLevel();

	void isWin(int pin); // ��� �ǵ� <- ������ private�� �� ��������.
	//UI&UX
	void TTT_Tray(); // ������ ��º�
};
int main() {
	int stoper;
	TTT_Engine game;

	game.selectFirst();

	for (int i = 0; i < 5; i++) {
		game.TTT_Tray();
		game.input_select();
		game.isWin(1);
	}

	cin >> stoper;
}
void TTT_Engine::isWin(int pin) {
	bool hasWinner = false;
	cout << "�¸��˻�" << endl;
	for (int i = 0; i < 3; i++) {
		if (ground[i][0] == ground[i][1] && ground[i][1] == ground[i][2]) { // ������ Ŭ����
		//	cout << ground[i][0] << isInput[i][0] << endl;
			if (isInput[i][0] == false) {
				hasWinner = true;
				//break;
				continue;
			}
		}
		else if (ground[0][i] == ground[1][i] && ground[1][i] == ground[2][i]){ // ������ Ŭ����
			if (isInput[0][i] == false) {
				hasWinner = true;
				//break;
				continue;
			}
		}
	}	
	if (hasWinner == true) {
		switch (pin) {
		case 1: cout << "'X' ���� �¸�!" << endl; break;
		case 2: cout << "'Y' ���� �¸�!" << endl; break;
		}
	}
}
void TTT_Engine::Ahead(int level) { // 1. ���� ĭ�� ��ΰ�. 2. ���ɼ��� �ִ� �ڸ��� �ִ°�. 3. ������ ��Ѱ�. 4. 2~3�� ������ �ݺ��ϸ� �� �� �޶����°�.
	int x_axis;
	int y_axis;
	int blank; // '�� ĭ ����'
	blank=place_trace();  // 1��.
	for (int i = 0; i < level; i++) {

	}

	input_pin(x_axis + 1, y_axis + 1);

}
int TTT_Engine::place_trace() {
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (isInput[i][j] == true) {
				place[count][0] = i;
				place[count][1] = j;
				count++;
			}
		}
	}
	return count + 1;
}
//int * 
void TTT_Engine::initall() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ground[i][j] = 0;
			isInput[i][j] = true;
		}
	}
	init_place();
}
void TTT_Engine::init_place() {
	for (int i = 0; i < 0; i++) {
		place[i][0] = -1;
		place[i][1] = -1;
	}
}
void TTT_Engine::input_select() {
	while (1) {
		cout << "Input �Ҵ�" << endl;
		cout << "(1,1)~(3,3)" << endl;
		cin >> axis[0] >> axis[1];

		if (axis[0] > 3 || axis[0] <= 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
		else if (axis[1] > 3 || axis[1] <= 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
		else if (isInput[axis[0]-1][axis[1]-1] == false) {
			cout << "�̹� ����� ��ǥ�Դϴ�" << endl;
		}
		else {
			input_pin(axis[0],axis[1]);
			return;
		}
			//break;
	}
}
void TTT_Engine::input_pin(int x,int y) {
	x = x - 1;
	y = y - 1;
	isInput[x][y] = false;
	if (isFirst == true) {
		ground[x][y] = 1;
	}
	else {
		ground[x][y] = 2;
	}
}
bool TTT_Engine::selectFirst() {
	int selecter;
	cout << "���� : X, �İ� : O" << endl;
	cout << "��/�İ��� �����ϼ���" << endl;
	cout << "(���� ���� �İ����� ���õ˴ϴ�)" << endl;
	cout << "��:1 / ��:2 :::: ";

	cin >> selecter;
	if (selecter == 1) {
		return true;
	}
	else
		return false;
}
void TTT_Engine::TTT_Tray() {
	cout << "-----------------------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "[";
		for (int j = 0; j < 3; j++) {
			if (isInput[i][j] == true) {
				cout << "| ";
			}
			else {
				if (ground[i][j] == 1) {
					cout << "|X";
				}
				else if (ground[i][j] == 2)
					cout << "|O";
				else
					cout << "| ";
			}
		}
		cout << "|]";
		if (i==0) cout<< "      ���̵� : "<< level << endl;
		else if (i == 1) cout << "      NN ȸ��" << endl;
		else if (i == 2) cout << "      NN ������" << endl;
	}
}
void TTT_Engine::selectLevel() {
	cout << "���̵��� �������ּ��� :: ����<<1,2,3<<�����" << endl;
	int input;
	cin >> input;
	switch (input) {
	case 1: level = 1; break;
	case 2: level = 2; break;
	case 3: level = 3; break;
	default: level = 2; break;
	}
}