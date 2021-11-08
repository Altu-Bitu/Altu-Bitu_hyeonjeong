#include<iostream>
#include<vector>

using namespace std;
const int INF = 1e4 * 5;
void floydWarshall(int n, vector<vector<int>> &event) {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int dist = event[i][k] + event[k][j]; //중간에 k를 거쳐서 i에서 j로 감
					event[i][j] = min(event[i][j], dist); //i->j, i->k->j 중 더 짧은 곳으로 감
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, s;
	int num1, num2;
	//입력
	vector<vector<int>> event; //알고 이쓴ㄴ 사건 전후 관계 저장

	cin >> n >> k; //전체사건, 알고 있는사건

	event.assign(n+1, vector<int>(n+1, INF));
	for (int i = 0; i < n; i++)
		event[i][i] = 0;
	
	for (int i = 0; i < k; i++) {
		cin >> num1 >> num2;
		event[num1][num2] = 1; //아는 사건은 1로
	}
	
	//플로이드-워셜
	floydWarshall(n, event);

	//유추할 사건 수 입력
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> num1 >> num2;
		if (event[num1][num2] < INF)
			cout << -1<<'\n';
		else if (event[num2][num1] < INF)
			cout << 1<<'\n';
		else
			cout << 0<<'\n';
	}

	return 0;
}