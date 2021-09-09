#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct grade {
	int doc;
	int inter;
}grade;
vector<grade> person;

int testgrade(int n) {//���Ի�� ����
	int cnt = 1, intergrade = person[0].inter;
	for (int i = 1; i < n; i++) {
		if (intergrade > person[i].inter) {
			cnt++;
			intergrade = person[i].inter;
		}
	}
	return cnt;
}

bool cmp(grade a, grade b) { //����
	return a.doc < b.doc;
}

int main() {
	int t, n;
	int cnt = 0;

	cin >> t;//���̽� ����

	for (int i = 0; i < t; i++) {
		cin >> n; //������ ��
		person.assign(n, { 0,0 });
		for (int j = 0; j < n; j++) {
			cin >> person[j].doc >> person[j].inter;
		}
		sort(person.begin(), person.end(), cmp);//�����ɻ� ���� ��������
		cnt = testgrade(n); //���Ի�� ����
		cout << cnt << endl; //���� �ο��� ���
	}


	return 0;
}