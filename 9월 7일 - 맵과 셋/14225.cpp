//문자열 집합

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

set<string> s; //s집합 문자열

int main() {
	int n, m, count = 0;
	string str,input; //s문자열 , 검사할 문자열

	cin >> n >> m;

	for (int i = 0; i < n; i++) { //s 집합 입력
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < m; i++) {//검사할 문자열 입력하면서 집합s 포함여부 바로 검사
		cin >> input;
		if (s.find(input) != s.end()) //find함수로 문자열 존재하는지 확인
			count++;
	}
	cout << count;

	return 0;
}