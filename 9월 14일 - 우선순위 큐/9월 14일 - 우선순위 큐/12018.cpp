#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;
priority_queue<int> pq;
vector<int> minimum; //�ּ��� �ʿ��� ���ϸ���

void mileageNeed(int applypeople, int student, int n) {
	int stu;


	while (applypeople--) {//�л��� ���ϸ��� ���� �Է�
		cin >> stu;
		pq.push(stu);
	}

	if (applypeople < student) {
		minimum.push_back(0); //�����ο��� �� ������ �׻� ��
		return;
	}

	while (student--) {//�ּ��� �ʿ��� ���ϸ��� ����
		stu = pq.top();
		 pq.pop();
	}
	 minimum.push_back(stu);
	 for (int i = 0; i < n; i++) {
		 cout << minimum[i] << ', ';
	 }
}

int mileageSort(int m, int n) {
	int subject = 0, i=0, num=0;
	sort(minimum.begin(), minimum.end());

	for (int i = 0; i < n; i++) {
		cout << minimum[i] << ', ';
	}
	while(m>0){
		if (minimum[i] == 0) {
			subject++; m -= 1;
		}
		else {
			num = m - minimum[i];
			if (num >= 0) {
				subject++; m = num;
			}
		}
	}
	return subject;
}

int main() {
	int n, m;
	int mileage;

	cin >> n >> m; //�����, ���ϸ��� ��

	int applypeople, student;//��û�� �����, �����ο�
	while (n--) {
		cin >> applypeople >> student;
		mileageNeed(applypeople,student,n); 
	}

	mileage = mileageSort(m, n);
	cout << mileage;
}