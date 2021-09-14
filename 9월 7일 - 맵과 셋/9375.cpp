//패션왕 신해빈

#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

map<string, int> clothes; //<옷종류, 옷개수>

void clothinput(int m) { //옷 종류입력,대입
	string cloth, type; //옷, 종류
	for (int i = 0; i < m; i++) {
		cin >> cloth >> type;
		if (clothes.find(type) == clothes.end()) { //처음 입력된 옷종류인 경우
			clothes[type] = 1;
		}
		else {
			clothes[type]++;//같은 옷 종류이면 옷 개수 증가
		}
	}
}

void output() {
	int day=1;
	//총 일수는 -> 각 옷종류에 대한 (의상개수 +1) 곱해주고 - (알몸인 경우)
	for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
		day *= (iter->second + 1);
	}
	cout << day - 1 << endl;
}

void clearFunc() {
	clothes.clear();
}
int main() {
	int n, m=0; //테스트수, 의상종류
	cin >> n;//테스트 수 입력

	for (int i = 0; i < n; i++) {
		cin >> m;
		clothinput(m);
		output(); //결과 출력
		clearFunc(); //초기화
	}
	return 0;
}