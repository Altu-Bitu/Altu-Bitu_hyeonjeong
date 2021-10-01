#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

const int SIZE = 7;//배열 크기
set<int> num;//중복되는것 제거하면서 저장
int seq[SIZE]; //수열 저장
int n, m;//전역변수로 
void backtracking(int cnt) { //중복 허용하여 수열 뽑기
	if (cnt == m) {//기저 조건
		for (int i = 0; i < m; i++)
			cout << seq[i] << ' '; //출력하면서 끝내기
		cout << '\n';
		return;//출력 끝내고 횟수 남아있으면 수열 출력
	}
	for (auto iter = num.begin(); iter != num.end(); iter++) {
		seq[cnt]= *iter; //num에서 저장된것 수열배열에 저장하기
		backtracking(cnt + 1); //재귀로 중복허용(중복허용하며 m개의 자연수 출력)
	}
}

int main() {
	int input;//입력 받으며 저장할 것
	cin >> n >> m;// n개의 자연수, 자연수 m
	for (int i = 0; i < n; i++) {
		cin >> input;//입력 받기
		num.insert(input);//set함수로 입력받고 저장하면서 중복되는 수는 제거하기
	}


	backtracking(0);//백트래킹
	return 0;
}