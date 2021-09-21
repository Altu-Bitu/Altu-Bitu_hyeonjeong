#include<iostream>
#include<queue>

using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;//int 범위 넘어가므로 long long

void leastAdd(int m) {
	long long num1, num2, sum;
	while (m--) {
		num1 = pq.top(); pq.pop(); //가장 작은 수 저장하고 pop
		num2 = pq.top(); pq.pop();
		sum = num1 + num2;
		pq.push(sum); //더한 수 덮어 쓰기
		pq.push(sum); //더한 수 덮어 쓰기
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long num;
	cin >> n >> m; //카드의 개수, 카드 합체 개수

	while (n--) {
		cin >> num;
		pq.push(num);
	}

	leastAdd(m);

	long long sum = 0;

	while (!pq.empty()) { //카드 다 더하기
		sum += pq.top();
		pq.pop();
	}
	cout << sum;

	return 0;
}