#include <iostream>
#include "TTT_Head.h"

using namespace std;

class TTT_Engine{
	private :
	int ground[3][3];	// '������' (0 - ���� / 1 - X / 2 - O)
	bool isInput[3][3]; // ground�� ���� �� / ���� �ֳ� ���� �Ǵ� (true = ������� / false = �� ����)

	void initall(); // �ʱ�ȭ �Լ�
	
	public :
	int level=1; // ������
	bool isFirst=true; // ��,�İ�
	int axis[2]; // 0 - x��, 1 - y��


	//�ܺ� ��Ʈ�� �κ�
	bool selectFirst(); // ���İ� ����
	void input_select(); // ����
};
void TTT_Engine::initall() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			ground[i][j] = 0;
			isInput[i][j] = true;
		}
	}
}
void TTT_Engine::input_select() {
	while (1) {
		cout << "Input �Ҵ�" << endl;
		cin >> axis[0] >> axis[1];

		if (axis[0] > 3 || axis[0] < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
		else if (axis[1] > 3 || axis[1] < 0) {
			cout << "�߸��� �Է��Դϴ�" << endl;
		}
		else if (isInput[axis[0]][axis[1]] == true) {
			cout << "�̹� ����� ��ǥ�Դϴ�" << endl;
		}
		else
			return;
			//break;
	}
}
bool TTT_Engine::selectFirst() {
	int selecter;
	
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