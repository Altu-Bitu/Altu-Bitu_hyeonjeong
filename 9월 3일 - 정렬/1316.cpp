#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> str1;

int cnt = 0;

void wordchecker(string str) {
	int visited[26] = { 0 };
	for (int i = 0; i < str.length(); i++) {
		if (i == 0) {
			visited[(int)str[i] - 97] = 1; //���ĺ� ������ ���� �湮 ǥ��
			continue;
		}

		if (visited[(int)str[i] - 97] == 1 && str[i - 1] != str[i]) //�湮�� ���� ���ӵ� ���ڿ� �ƴѰ��
			return;

		visited[(int)str[i] - 97] = 1;
	}
	cnt++;
}


//visited�Ѱ� true�� ����
int main() {
	int n, result = 0;


	cin >> n;
	str1.assign(n, "");

	//�Է�
	for (int i = 0; i < n; i++) {
		cin >> str1[i];
		wordchecker(str1[i]);
	}

	cout << cnt;

	return 0;
}