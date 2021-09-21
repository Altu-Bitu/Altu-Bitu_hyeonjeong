#include<iostream>
#include<queue>

using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;//int ���� �Ѿ�Ƿ� long long

void leastAdd(int m) {
	long long num1, num2, sum;
	while (m--) {
		num1 = pq.top(); pq.pop(); //���� ���� �� �����ϰ� pop
		num2 = pq.top(); pq.pop();
		sum = num1 + num2;
		pq.push(sum); //���� �� ���� ����
		pq.push(sum); //���� �� ���� ����
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	long long num;
	cin >> n >> m; //ī���� ����, ī�� ��ü ����

	while (n--) {
		cin >> num;
		pq.push(num);
	}

	leastAdd(m);

	long long sum = 0;

	while (!pq.empty()) { //ī�� �� ���ϱ�
		sum += pq.top();
		pq.pop();
	}
	cout << sum;

	return 0;
}