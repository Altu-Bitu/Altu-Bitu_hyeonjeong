#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
priority_queue<int> pq;
vector<int> minimum; //�ּ��� �ʿ��� ���ϸ���

void mileageNeed(int applypeople, int student) {
	int stu = 0;
	int apply = applypeople;


	while (apply--) {//�л��� ���ϸ��� ���� �Է�
		cin >> stu;
		pq.push(stu);
	}

	if (applypeople < student) {
		minimum.push_back(0); //�����ο��� �� ������ �׻� ��
	}
	else {
		while (student--) {//�ּ��� �ʿ��� ���ϸ��� ����
			stu = pq.top();
			pq.pop();

		}
		minimum.push_back(stu);
	}

	while (!pq.empty()) {
		pq.pop();
	}

}

int mileageSort(int m, int n) {
	int subject = 0, num = 0, i = 0;
	sort(minimum.begin(), minimum.end());

	while (m > 0 && i < n) {
		if (minimum[i] == 0) {
			subject++; m = m - 1;
		}
		else {
			num = m - minimum[i];
			if (num >= 0) {
				subject++; m = num;
			}
			else
				break;
		}
		i++;
	}
	return subject;
}

int main() {
	int n, m;
	int mileage;

	cin >> n >> m; //�����, ���ϸ��� ��

	int applypeople, student;//��û�� �����, �����ο�
	int i = n;
	while (i--) {
		cin >> applypeople >> student;
		mileageNeed(applypeople, student);
	}

	cout << mileageSort(m, n) << endl;


	return 0;
}