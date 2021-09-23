#include<iostream>

using namespace std;

int factorial(int n) {
	int num=1;
	for (int i = 1; i <= n; i++) {
		num *= i;
	}
	return num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int num1, num2, num3;
	num1 = factorial(n); //n!
	num2 = factorial(n - k); //(n-k)!
	num3 = factorial(k); // k!

	cout << num1 / (num2 * num3);
	return 0;
}