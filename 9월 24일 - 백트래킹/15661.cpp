#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > ability;
vector<int> rank;
void abilitySum(int a,int b) {
	vector<bool> check;//체크할 변수 만들기
	check.assign(a+b, 0);
	int sum = 0;
	int num = 0;
	for (int i = 0; i <= b; i++) {
		check[i] = 1;
		for (int j = 1; j < a; j++) {
			if (i == j)
				continue;

			while (num < a-1) {
				if (check[j] == 0) {
					check[j] = 1;
				}
				num++;
			}
		}
	}
		
}

void abilityRec(int a, int b) {//(스타트, 링크)
	if (b <= (a+b)/2 )//탈출조건
		return;
	else {
		abilitySum(a, b);
		abilityRec(a + 1, b - 1);
	}

}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, input;
	cin >> n; 
	ability.assign(n, vector<int>(n, 0)); //n*n 이차원 배열 선언

	for (int i = 0; i < n; i++) { //능력치 입력받기
		for (int j = 0; j < n; j++) {
			cin >> input;
			ability[i][j] = input;
		}
	}
	
	abilityRec(2, n - 2); //팀 나누기(스타트팀, 링크팀)




	return 0;
}