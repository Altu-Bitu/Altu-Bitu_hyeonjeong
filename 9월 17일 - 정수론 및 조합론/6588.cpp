#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<bool> num;
const int MAX = 1000001; //미리 제거하기 위해 max선언

void isPrime() {
	num[0] = num[1] = false;
	for (int i = 2; i <= sqrt(MAX-1); i++) {
		if (num[i]) {
			for (int j = i * i; j < MAX; j += i) //제곱한것들은 이미 소수 아니므로
				num[j] = false;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n=1,a,b;
	

	num.assign(MAX, true);
	isPrime(); //소수인지 판단

	while (1) {
		cin >> n;
		if (n == 0)
			break;
		bool test = false;
		for (int i = 3; i < n; i+=2) {
			a = i;
			b = n - i;
			if (num[a] && num[b]) { //둘다 소수라면
				cout << n << " = " << a << " + " << b<<endl;
				test = true;
				break;
			}
		}
			if(!test)
				cout << "Goldbach's conjecture is wrong."<<endl;
		}
	
	return 0;
}