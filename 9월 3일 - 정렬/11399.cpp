#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> p;
int main() {
	int n, sum = 0, acc = 0;

	cin >> n;
	p.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}

	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		acc += p[i];
		sum = sum + acc;
	}

	cout << sum;

	return 0;
}