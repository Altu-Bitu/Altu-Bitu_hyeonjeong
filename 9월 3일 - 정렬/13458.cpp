#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a; //응시자 수

int main() {
	int n, b, c;
	long long cnt = 0; //감독관 수
	int j = 0;

	//입력
	cin >> n; //시험장 수
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