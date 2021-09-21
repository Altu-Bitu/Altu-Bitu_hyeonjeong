#include<iostream>
#include<queue>

using namespace std;

struct arr { //�켱���� ����
	bool operator() (int x, int y) {
		if (abs(x) != abs(y))
			return abs(x) > abs(y); //���밪 �������� Top �����ϵ��� �Ѵ�
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
		if (x == 0) {//���
			if (p.empty()) // ����ִٸ� 0 ���
				result = 0;
			else {
				result = p.top();//���� ���� �� ���
				p.pop();
			}
			cout << result << endl;
		}
		else //i!=0�̸� �߰�
			p.push(x);

	}
	return 0;
}