#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct grade {
	int doc;
	int inter;
}grade;
vector<grade> person;

int testgrade(int n) {//신입사원 선발
	int cnt = 1, intergrade = person[0].inter;
	for (int i = 1; i < n; i++) {
		if (intergrade > person[i].inter) {
			cnt++;
			intergrade = person[i].inter;
		}
	}
	return cnt;
}

bool cmp(grade a, grade b) { //정렬
	return a.doc < b.doc;
}

int main() {
	int t, n;
	int cnt = 0;

	cin >> t;//케이스 개수

	for (int i = 0; i < t; i++) {
		cin >> n; //지원자 수
		person.assign(n, { 0,0 });
		for (int j = 0; j < n; j++) {
			cin >> person[j].doc >> person[j].inter;
		}
		sort(person.begin(), person.end(), cmp);//서류심사 성적 순서나열
		cnt = testgrade(n); //신입사원 선발
		cout << cnt << endl; //선발 인원수 출력
	}


	return 0;
}