#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int maxtri = 0;
vector<int> tri;
int makeTri(int n) {//삼각형 만드는 함수
	for (int i = 0; i < n - 2; i++) 
		if (tri[i] < tri[i + 1] + tri[i + 2])//삼각형 만들어지는 조건
			return maxtri = tri[i] + tri[i + 1] + tri[i + 2];

	return -1;//삼각형 안되는 경우 반환
}

int main() {
	int n,input;
	cin >> n;
	for (int i = 0; i < n; i++) {//입력받기
		cin >> input;
		tri.push_back(input);
	}
	sort(tri.begin(), tri.end(),greater<int>()); //정렬

	cout<<makeTri(n);//삼각형 만들고 길이 출력
	return 0;
}