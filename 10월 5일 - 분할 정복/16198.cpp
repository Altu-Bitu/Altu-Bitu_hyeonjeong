#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int energynum = 0;
void energyMax(vector<int> energy,int maxN) {

	if (energy.size() == 2) { //기저조건
		energynum = max(energynum, maxN); //합의 최대와 현재합 비교해서 저장
		return;
	}
		
	for (int i = 1; i < energy.size() - 1; i++) {
		int energymax = maxN;
		int num = energy[i];
		vector<int> ener;
		copy(energy.begin(), energy.end(), ener.begin()); //에너지크기 복사본 만들기

		maxN += energy[i - 1] * energy[i + 1];//에너지 값 모으기
		energy.erase(ener.begin() + i); //i번째 에너지 제거
		energyMax(ener,maxN); //i번째 에너지 제거한 배열 전달
		maxN = energymax; //최대 값 복구
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,maxN=0;
	vector<int> energy;
	cin >> n;
	energy.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> energy[i];//입력
	energyMax(energy,maxN);//최대 에너지 합 구하기

	cout << energynum; //에너지 최대 합 출력

	return 0;
}

/*
https://transferhwang.tistory.com/432
참고해서 해결하려 했지만 오류가 났습니다... 추가제출때 공부해서 제출하겠습니다.
*/