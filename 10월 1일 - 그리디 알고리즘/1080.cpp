#include<iostream>
#include<vector>

using namespace std;
vector<vector<int> > a;
vector<vector<int> > b; 
bool check[50][50] = { false, };
int result = 0;//연산 횟수

void arrayAssign(int n, int m,vector<vector<int> > &x) {//입력받는 함수
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> x[i][j];
}

void compCheck(vector<vector<int> > &a, vector<vector<int> > &b,int n,int m) {// a행렬과 b행렬 비교해서 다른 것은 true로 변한
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == b[i][j]) //a행렬과 b행렬이 같으면
				continue;
			check[i][j] = true; //다르면 check배열 true로 변경
			
		}
	}
}

int checkEnd(int n, int m) { //check배열에 true값 있는지확인
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (check[i][j]) 
				return -1;
		
	return result;
}

void changeArray(vector<vector<int> > &a, vector<vector<int> > &b, int n, int m) {//행렬 바꾸는데 필요한 연산 구하는 함수
	int x = n, y = m;
	for (int i = 0; i <= n - 3; i++) {//(n-3, m-3)까지 진행하기
		for (int j = 0; j <= m - 3; j++) {
			if (check[i][j]) { //만약 a배열 b배열 서로 다르면(check배열 true이면)
				for (int k = i; k < i + 3; k++) {//3*3행렬 모두 바꾸기
					for (int l = j; l < j + 3; l++) {
						a[k][l] = 1 - a[k][l]; //b와 같게 바꾸기(1 -> 0, 0 -> 1)
						check[k][l] = 1- check[k][l]; //반대로 표현
					}
				}
				result++;
				if (checkEnd(x, y) == -1) //끝났는지 체크
					continue;
				else
					break;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m; //행,열 출력
	a.assign(n, vector<int>(m, 0)); //n행 m열 배열
	b.assign(n, vector<int>(m, 0)); //n행 m열 배열

	arrayAssign(n, m, a); arrayAssign(n, m, b);
	compCheck(a, b, n, m);//서로 다르다면 check배열 true로

	changeArray(a, b, n, m);//A를 B로 바꾸기

	cout<< checkEnd(n, m); //true값 있는지 확인

	return 0;
}