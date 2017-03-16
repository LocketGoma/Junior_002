#include <iostream>
#include "TTT_Head.h"

using namespace std;

class TTT_Engine{
	private :
	int ground[3][3];	// '게임판' (0 - 없음 / 1 - X / 2 - O)
	bool isInput[3][3]; // ground와 같이 돔 / 뭔가 있나 없나 판단 (true = 비어있음 / false = 차 있음)

	void initall(); // 초기화 함수
	
	public :
	int level=1; // 레벨링
	bool isFirst=true; // 선,후공
	int axis[2]; // 0 - x축, 1 - y축


	//외부 컨트롤 부분
	bool selectFirst(); // 선후공 선택
	void input_select(); // 선택
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
		cout << "Input 할당" << endl;
		cin >> axis[0] >> axis[1];

		if (axis[0] > 3 || axis[0] < 0) {
			cout << "잘못된 입력입니다" << endl;
		}
		else if (axis[1] > 3 || axis[1] < 0) {
			cout << "잘못된 입력입니다" << endl;
		}
		else if (isInput[axis[0]][axis[1]] == true) {
			cout << "이미 사용한 좌표입니다" << endl;
		}
		else
			return;
			//break;
	}
}
bool TTT_Engine::selectFirst() {
	int selecter;
	
	cout << "선/후공을 선택하세요" << endl;
	cout << "(임의 값은 후공으로 선택됩니다)" << endl;
	cout << "선:1 / 후:2 :::: ";

	cin >> selecter;
	if (selecter == 1) {
		return true;
	}
	else
		return false;
}