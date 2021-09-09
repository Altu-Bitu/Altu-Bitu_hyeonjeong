#include<iostream>
#include<vector>

using namespace std;

vector<vector<char> > a;
int main() {
	int n, star;
	int i, j;
	cin >> star;
	n = 1 + 4 * (star - 1);
	a.assign(n, vector<char>(n, ' '));


	for (i = 0; i < n / 2 + 1; i += 2) {
		for (j = i; j < n - i; j++) {
			a[i][j] = '*';
			a[n - (i + 1)][j] = '*';

		}

	}
	for (i = 0; i < n / 2 + 1; i += 2) {
		for (j = i + 1; j < n - (i + 1); j++) {
			a[j][i] = '*'; 
			a[j][n - (i + 1)] = '*'; 
		}
	}


	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			cout << a[i][j];
		cout << endl;
	}
	return 0;
}