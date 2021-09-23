#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, p;
	cin >> n >> p; //음의수, 프렛수
	
	int move = 0; //움직인수
	stack<int> guitar[7];//1-6까지 줄의수

	while (n--) {
		int n1, n2;
		cin >> n1 >> n2;//줄번호, 프렛번호

		while (true) { 
			if (guitar[n1].empty() || guitar[n1].top() < n2) {// 비거나 자기보다 작은 프렛번호 만난경우
				guitar[n1].push(n2);
				move ++;
				break;
			}
			if (guitar[n1].top() == n2) //같은 프렛 번호 누른경우
				break;
			
			if (guitar[n1].top() > n2) { //자기보다 더 큰 프렛번호 있는경우
				guitar[n1].pop();
				move++;
			}

		}
	}

	cout << move;

	return 0;
}