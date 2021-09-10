#include<iostream>
#include<vector>

using namespace std;

vector<vector<char> > a;

void drawStar(int n, int row, int col) {//별그려주는 함수
	for (int i = col; i < col + n; i++) {//첫째줄,마지막줄 채우기
		a[row][i] = '*'; //첫줄
		a[row + (n - 1)][i] = '*'; //마지막 줄
	}

	for (int i = row + 1; i < row + (n - 1); i++) {//행 바뀌면서 옆줄 채우기
		a[i][col] = '*';
		a[i][col + (n - 1)] = '*';
	}
}

void starArray(int n, int row, int col) {
	drawStar(n, row, col);//별그려주기
	if (n == 1) {
		return;
	}
	starArray(n - 4, row + 2, col + 2); //재귀함수
}

int main() {
	int n, star;
	int i, j;
	cin >> star;
	n = 1 + 4 * (star - 1); //별개수
	a.assign(n, vector<char>(n, ' ')); //배열에 공백넣어주기

	starArray(n, 0, 0);

	for (i = 0; i < n; i++) { //출력
		for (j = 0; j < n; j++)
			cout << a[i][j];
		cout << endl;
	}

	return 0;
}