#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a; //������ ��

int main() {
	int n, b, c;
	long long cnt = 0; //������ ��
	int j = 0;

	//�Է�
	cin >> n; //������ ��
	a.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		a[i] = a[i] - b;
		cnt++;
		if (a[i] > 0) {
			cnt += a[i] / c;
			if (a[i] % c)
				cnt++;
		}
	}

	cout << cnt;
	return 0;
}