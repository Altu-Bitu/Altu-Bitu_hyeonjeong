#include<iostream>
#include<queue>
#include<vector>

using namespace std;

typedef pair<int, int> ci;
const int INF = 1e5;
int x[4] = { 1, -1, 0, 0 };
int y[4] = { 0, 0, 1, -1 };

int Dijstra(int n, vector<vector<int>>& arr) {
	vector<vector<int>> dist(n, vector<int>(n, INF));
	priority_queue<ci> pq; 

	dist[0][0] = arr[0][0];
	pq.push({ 0,0 }); //처음시작은 (0,0)

	while (!pq.empty()) {
		int xn = pq.top().first; //x좌표
		int yn = pq.top().second; //y좌표
		pq.pop();

		for (int i = 0; i < 4; i++) { //상하좌우 좌표 더하면서 크기비교
			int cx = x[i] + xn;
			int cy = y[i] + yn;

			if (cx >= 0 && cy >= 0 && cx < n && cy < n) {
				if (dist[cx][cy] > arr[cx][cy] + dist[xn][yn]) {
					dist[cx][cy] = arr[cx][cy] + dist[xn][yn]; //이동할 정점과 현재 노드 더한값이 더 작으면 dist변경
					pq.push({ cx,cy });
				}

			}
		}
	}
	return dist[n - 1][n - 1];
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n=1, cnt = 1;
	

	while (1) {
		cin >> n;
		if (n == 0)
			break;
		int ans;
		vector<vector<int>> arr;
		arr.assign(n, vector<int>(n, 0)); //n*n차원 행렬

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
		ans = Dijstra(n, arr); //다익스트라 최단경로 구하기
		cout << "Problem " << cnt++ << ": " << ans<<'\n'; //출력
		
	}

	return 0;
}


/*
참고
https://yabmoons.tistory.com/388

*/