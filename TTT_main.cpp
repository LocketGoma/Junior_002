#include <iostream>
#include "TTT_Head.h"

using namespace std;

class TTT_Engine{
	private :
	int ground[3][3];	// '게임판' (0 - 없음 / 1 - X / 2 - O)
	bool isInput[3][3]; // ground와 같이 돔 / 뭔가 있나 없나 판단 (true = 비어있음 / false = 차 있음)
	int place[9][2]; // 넣을수 있는 자리의 가지 수. <- 최대 9개.

	int level = 3; // 난이도. 기본 3 (Ahead 수행 회수)

	void initall(); // 초기화 함수
	void init_place(); // 가지 수 초기화 함수.
	int place_trace(); // place에 빈 칸 찾아주는 함수.

	void Evaluate(); // Evaluate (최적화) 함수
	void Ahead(int level); // '내다보기' 함수
	void input_pin(int x,int y); // '핀 올리기'
	//void isWin(int pin); // 결과 판독 <- 원래는 private에 가 있을거임.

	public :

	bool isFirst=true; // 선,후공
	int axis[2]; // 0 - x축, 1 - y축


	//외부 컨트롤 부분
	bool selectFirst(); // 선후공 선택
	void input_select(); // 선택
	void selectLevel();

	void isWin(int pin); // 결과 판독 <- 원래는 private에 가 있을거임.
	//UI&UX
	void TTT_Tray(); // 게임판 출력부
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
	cout << "승리검사" << endl;
	for (int i = 0; i < 3; i++) {
		if (ground[i][0] == ground[i][1] && ground[i][1] == ground[i][2]) { // 가로줄 클리어
		//	cout << ground[i][0] << isInput[i][0] << endl;
			if (isInput[i][0] == false) {
				hasWinner = true;
				//break;
				continue;
			}
		}
		else if (ground[0][i] == ground[1][i] && ground[1][i] == ground[2][i]){ // 세로줄 클리어
			if (isInput[0][i] == false) {
				hasWinner = true;
				//break;
				continue;
			}
		}
	}	
	if (hasWinner == true) {
		switch (pin) {
		case 1: cout << "'X' 유저 승리!" << endl; break;
		case 2: cout << "'Y' 유저 승리!" << endl; break;
		}
	}
}
void TTT_Engine::Ahead(int level) { // 1. 남은 칸이 몇개인가. 2. 가능성이 있는 자리가 있는가. 3. 상대방은 어떠한가. 4. 2~3을 여러번 반복하면 좀 더 달라지는가.
	int x_axis;
	int y_axis;
	int blank; // '빈 칸 개수'
	blank=place_trace();  // 1번.
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
		cout << "Input 할당" << endl;
		cout << "(1,1)~(3,3)" << endl;
		cin >> axis[0] >> axis[1];

		if (axis[0] > 3 || axis[0] <= 0) {
			cout << "잘못된 입력입니다" << endl;
		}
		else if (axis[1] > 3 || axis[1] <= 0) {
			cout << "잘못된 입력입니다" << endl;
		}
		else if (isInput[axis[0]-1][axis[1]-1] == false) {
			cout << "이미 사용한 좌표입니다" << endl;
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
	cout << "선공 : X, 후공 : O" << endl;
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
		if (i==0) cout<< "      난이도 : "<< level << endl;
		else if (i == 1) cout << "      NN 회차" << endl;
		else if (i == 2) cout << "      NN 선택중" << endl;
	}
}
void TTT_Engine::selectLevel() {
	cout << "난이도를 선택해주세요 :: 쉬움<<1,2,3<<어려움" << endl;
	int input;
	cin >> input;
	switch (input) {
	case 1: level = 1; break;
	case 2: level = 2; break;
	case 3: level = 3; break;
	default: level = 2; break;
	}
}