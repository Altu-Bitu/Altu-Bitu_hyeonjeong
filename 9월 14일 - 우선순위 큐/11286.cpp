#include<iostream>
#include<queue>

using namespace std;

struct arr { //우선순위 정의
	bool operator() (int x, int y) {
		if (abs(x) != abs(y))
			return abs(x) > abs(y); //절대값 작은것이 Top 유지하도록 한다
		else
			return x > y;

	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, result;
	priority_queue<int, vector<int>, arr> p;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {//출력
			if (p.empty()) // 비어있다면 0 출력
				result = 0;
			else {
				result = p.top();//가장 작은 수 출력
				p.pop();
			}
			cout << result << endl;
		}
		else //i!=0이면 추가
			p.push(x);

	}
	return 0;
}