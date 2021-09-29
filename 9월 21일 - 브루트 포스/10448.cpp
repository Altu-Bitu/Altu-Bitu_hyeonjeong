#include<iostream>
#include<vector>

using namespace std;

vector<int> triangle;
void triExpress() {
	int n=1;
	while (n * (n + 1) / 2 < 1000) {//1000이하인 삼각수 Tn구하기
		triangle.push_back(n * (n + 1) / 2);
		n++;
	}
}


bool triangleNumber(int m) {//브루트포스로 다 돌면서 찾기
	for (int i = 0; i < triangle.size(); i++) {
		for (int j = 0; j < triangle.size(); j++) {
			for (int k = 0; k < triangle.size(); k++) {
				if (triangle[i] + triangle[j] + triangle[k] == m)
					return 1;//찾은 경우 true 반환
			}
		}
	}
	return 0; //합을 만족하는 경우가 없는 경우
}

int main() {
	int n,m;
	cin >> n;

	triExpress(); //삼각수 공식으로 구해서 배열에 저장하기
	for (int i = 0; i < n; i++) {
		cin >> m;
		cout<< triangleNumber(m)<<endl;//합을 만족시키는 값 찾기
	}
	

	return 0;
}