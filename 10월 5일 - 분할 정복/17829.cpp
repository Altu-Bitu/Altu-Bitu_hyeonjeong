#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int sizComp(int i,int j,vector<vector<int> > pulling) {//두번째로 큰 값 반환하는함수
	vector<int>siz;
	
	siz.push_back(pulling[i][j]);
	siz.push_back(pulling[i][j + 1]);
	siz.push_back(pulling[i + 1][j]);
	siz.push_back(pulling[i + 1][j + 1]);
	sort(siz.begin(), siz.end());

	return siz[2];
}

void Divide(int n, vector<vector<int> > pulling) {
	if (n == 1) {
		cout << pulling[0][0];
		return;
	}
	vector<vector<int> >second(n / 2, vector<int>(n / 2, 0)); //두번째로 큰 수 받을 배열 선언(n/2,n/2)

	for (int i = 0; i <= n - 2; i += 2) {//두 칸씩 이동하면서 값 저장
		for (int j = 0; j <= n - 2; j += 2) {
			second[i / 2][j / 2] = sizComp(i, j, pulling);
		}
	}
	Divide(n / 2, second);
}


int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int> > pulling;//이차원배열 선언
	pulling.assign(n, vector<int>(n, 0)); 
	for (int i = 0; i < n; i++) //행렬에 값 입력받기
		for (int j = 0; j < n; j++)
			cin >> pulling[i][j];
	
	Divide(n, pulling);

	return 0;
}