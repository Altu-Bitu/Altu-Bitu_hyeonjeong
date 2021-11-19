#include<iostream>
#include<vector>

using namespace std;

#define MAX 1000001
int dp[MAX] = { 0, }; //연산의 횟수를 저장할 배열
int path[MAX] = { -1, }; //어떤 경로에서 온지 역추적하기위한 배열

void makeArray(int n) { //bottom-up 
	for (int i = 2; i <= n; i++) { 
		//1을 뺸다
		dp[i] = dp[i - 1] + 1; //1빼기는 모든 수에 적용됨
		path[i] = i - 1; //

		//3으로 나누기
		if (i % 3 == 0 & dp[i] > dp[i / 3] + 1) { //3으로 나눈값이 더 최단 경로면 갱신
			//3에서의 경로수를 이어갈지 현재 유지할지 결정
			dp[i] = dp[i / 3] + 1;
			path[i] = i / 3;
		}

		//2로 나누기
		if (i % 2 == 0 & dp[i] > dp[i / 2] + 1) {//현재 index보다 2로 나눴을때 저장된 값이 최소라면 그걸로 현재 dp배열 갱신
			dp[i] = dp[i / 2] + 1;
			path[i] = i / 2;
		}

	}
}

int main() {
	int n;

	//입력
	cin >> n; 
	makeArray(n);

	//출력
	cout << dp[n] << '\n'; //계산된 최솟값 출력
	for (int i = n; i >= 1; i=path[i]) { // 경로배열 이용해서 방법 출력
		cout << i << " ";
	}

	return 0;
}

/*
참고
dp 점화식 세우는데 어려움이 있어서 다른 분의 블로그를 참고하여 공부하고 혼자 해결해보았습니다.
https://prefer2.tistory.com/entry/%EB%B0%B1%EC%A4%80-12852%EB%B2%88-1%EB%A1%9C-%EB%A7%8C%EB%93%A4%EA%B8%B0-2-C
*/