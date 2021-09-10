#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> str1;

int cnt = 0;

void wordchecker(string str) {
	int visited[26] = { 0 };
	for (int i = 0; i < str.length(); i++) {
		if (i == 0) {
			visited[(int)str[i] - 97] = 1; //알파벳 순서에 따라 방문 표시
			continue;
		}

		if (visited[(int)str[i] - 97] == 1 && str[i - 1] != str[i]) //방문한 경우와 연속된 문자열 아닌경우
			return;

		visited[(int)str[i] - 97] = 1;
	}
	cnt++;
}


//visited한거 true로 설정
int main() {
	int n, result = 0;


	cin >> n;
	str1.assign(n, "");

	//입력
	for (int i = 0; i < n; i++) {
		cin >> str1[i];
		wordchecker(str1[i]);
	}

	cout << cnt;

	return 0;
}