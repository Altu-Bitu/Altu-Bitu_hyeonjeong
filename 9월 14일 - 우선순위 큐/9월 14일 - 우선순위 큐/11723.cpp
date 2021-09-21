//11723 집합
#include<iostream>

using namespace std;

bool s[21] = { false, };

void add(int x) { s[x] = true; }
void remove(int x) { s[x] = false; }
int check(int x) {
	return s[x];
}
void toggle(int x) {
	if (s[x] == true)
		s[x] = false;
	else
		s[x] = true;
}
void all() {
	for (int i = 1; i < 21; i++)
		s[i] = true;
	
}
void empty() {
	for (int i = 1; i < 21; i++)
		s[i] = false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, num; //연산 수, 전달 값
	string input; //연산 종류 입력

	cin >> m; //연산 수 입력

	while (m--) {
		cin >> input; //연산종류
		
		if (input == "add") {
			cin >> num; //전달 값 입력
			add(num);
			continue;
		}
		else if (input == "remove") {
			cin >> num;
			remove(num);
			continue;
		}
		else if (input == "check") {
			cin >> num;
			cout<< check(num)<<'\n';
			continue;
		}
		else if(input=="toggle"){
			cin >> num;
			toggle(num);
			continue;
		}
		else if (input == "all") {
			all();
			continue;
		}
		else if (input == "empty") {
			empty();
		}

	}

	return 0;
}