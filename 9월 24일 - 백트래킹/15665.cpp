#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int SIZE = 7;
set<int> num;//중복되는것 제거하면서 저장
int seq[SIZE]; //수열 저장
int n, m;
void backtracking(int cnt) { //중복 허용하여 수열 뽑기
	if (cnt == m) {//기저조건
		for (int i = 0; i < m; i++)
			cout << seq[i] << ' ';
		cout << '\n';
		return;
	}
	for (auto iter = num.begin(); iter != num.end(); iter++) {
		seq[cnt]= *iter;
		sequNumber(cnt + 1); //재귀로 중복허용
	}
}

int main() {
	int input;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input;
		num.insert(input);
	}


	backtracking(0);
	return 0;
}