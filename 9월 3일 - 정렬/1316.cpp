#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> str1;
vector<int> ct;

//sort해서 비교 or visited한거 true로 설정
int main() {
	int n, result = 0;

	cin >> n;
	str1.assign(n, "");
	ct.assign(n, 0);
	//입력
	for (int i = 0; i < n; i++) {
		cin >> str1[i];
	}

	//반복되는 단어 count x
	for (int i = 0; i < n; i++) {
		int j = 1, cnt = 1;
		while (str1[i][j]) {
			if (str1[i][j] != str1[i][j - 1])
				cnt++;
			j++;
		}
		ct[i] = cnt;
	}

	//정렬
	for (int i = 0; i < n; i++) {
		sort(str1[i].begin(), str1[i].end());
	}

	//정렬한것과 정렬 전 count 개수 비교
	for (int i = 0; i < n; i++) {
		int j = 1, cnt = 1;
		while (str1[i][j]) {
			if (str1[i][j] != str1[i][j - 1])
				cnt++;
			j++;
		}
		if (ct[i] == cnt)
			result++;
	}

	cout << result;

	return 0;
}