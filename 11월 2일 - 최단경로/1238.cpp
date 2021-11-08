#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e6;

vector<int> Dijstra(int n, vector<vector<ci>>& party, int x) { //정점수, 벡터, 파티위치
	vector<int> dist(n + 1, INF); //거리 배열 갱신할 벡터생성
	priority_queue<ci, vector<ci>, greater<>>pq; //큐의 우선순위를 크기 순으로

	dist[x] = 0;
	pq.push({ 0,x }); //파티위치를 큐에 삽입

	while (!pq.empty()) {
		int time = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (time > dist[node]) //이미 지났던건지 확인
			continue;
		for (int i = 0; i < party[node].size(); i++) {
			int nextnode = party[node][i].first; //다음 노드와 연결
			int nexttime = time + party[node][i].second; //다음 노드의 시간
			if (dist[nextnode] > nexttime) { 
				dist[nextnode]= nexttime; //거리배열 갱신
				pq.push({ nexttime,nextnode }); //다음 정점 큐에 넣기
			}
		}
	}

	return dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, x, u,v,t;
	
	cin >> n >> m >> x;
	vector<vector<ci>> forward(n + 1, vector<ci>(0)); 
	vector<vector<ci>> reverse(n + 1, vector<ci>(0));
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> t;
		forward[u].emplace_back(v, t); //시작정점, 도착정점, 시간
		reverse[v].emplace_back(u, t); //역방향(다익스트라 반대로)
	}

	//다익스트라 두번 진행
	vector<int> dep_dist = Dijstra(n, reverse, x); //파티로 가는 시간(시작 위치를 파티위치로 하고 간선 반대로 뒤집어서 다익스트라)
	vector<int> arr_dist = Dijstra(n, forward, x); //파티에서 다시 돌아오는 시간

	vector<int> size(n+1, 0);
	for (int i = 1; i <= n; i++) {
		size[i] = dep_dist[i] + arr_dist[i];
	}

	sort(size.begin(), size.end(), greater<>());
	cout << size[0] << '\n';

	return 0;
}