#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;
vector<int> num;

bool cmp(pair<int, int>& a, pair<int, int>& b) {//사용자 정의
	if (a.second == b.second)
		return a.first < b.first; //입력한 숫자는 오름차순으로
	return a.second > b.second;//내림차순
}

int mode(int n) {//최빈값
	map<int,int> frequ; //빈도수 저장해줄 배열
	for (int i = 0; i < n; i++)
		frequ[num[i] + 4000]++; 


	vector<pair<int, int>> fre(frequ.begin(), frequ.end()); //벡터 초기화
	sort(fre.begin(), fre.end(), cmp);//정렬
	
	if (fre.size() == 1 || fre[0].second != fre[1].second)//먼저 배열이 하나 있는지부터 확인하고 크기 비교
		return fre[0].first- 4000;
	else
		return fre[1].first - 4000;
	
}



int main() {
	int n;
	cin >> n;//입력
	num.assign(n, 0);//초기화
	int sum = 0;

	for (int i = 0; i < n; i++) {//정수 입력 받기
		int input;
		cin >> input;
		num[i] = input;
		sum += input; //입력 받으면서 합 
	}
	sort(num.begin(), num.end());//정렬
	cout << round((double)sum / n)<<endl; //산술평균
	cout << num[n / 2]<<endl; //중앙값
	cout<< mode(n)<< endl; //최빈값
	cout<<num[n-1]-num[0]<<endl; //범위

	return 0;
}