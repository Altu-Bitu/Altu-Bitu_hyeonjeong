#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> str1;
vector<int> ct;

//sort�ؼ� �� or visited�Ѱ� true�� ����
int main() {
	int n, result = 0;

	cin >> n;
	str1.assign(n, "");
	ct.assign(n, 0);
	//�Է�
	for (int i = 0; i < n; i++) {
		cin >> str1[i];
	}

	//�ݺ��Ǵ� �ܾ� count x
	for (int i = 0; i < n; i++) {
		int j = 1, cnt = 1;
		while (str1[i][j]) {
			if (str1[i][j] != str1[i][j - 1])
				cnt++;
			j++;
		}
		ct[i] = cnt;
	}

	//����
	for (int i = 0; i < n; i++) {
		sort(str1[i].begin(), str1[i].end());
	}

	//�����ѰͰ� ���� �� count ���� ��
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