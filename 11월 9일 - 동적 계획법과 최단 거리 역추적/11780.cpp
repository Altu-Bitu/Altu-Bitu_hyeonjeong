#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e7; //최대 n-1개의 간선을 지나게 됨

//역추적
vector<int> back(int s, int x, vector<vector<int>>& path) { //x: 도착점부터
    vector<int> result(0); //결과 출력할 뱅려 만들기
    while (x != 0) { //도착점 0 아닌경우 반복하기
        result.push_back(x); //0아닌 경우는 배열에 넣어주기
        x = path[s][x]; //다음 경로
    }
    return result; //역추적해서 저장된 값의 배열을 반환하기
}

//모든 (i, j)쌍의 역추적 결과값
vector<vector<int>> allPath(int n, vector<vector<int>>& path) { //경로 배열 역추적 결과값
    vector<vector<int>> ans(n * n); // 역추적 결과값 저장하기 위한 배열
    for (int i = 1; i <= n; i++) { //시작점(i)
        for (int j = 1; j <= n; j++) { //도착점(j)
            if (!path[i][j])//경로가 없으면
                continue;//돌아가기
            vector<int> result = back(i, j, path); //역추적해서 결과저장하는 배열에 넣기
            ans[(i - 1) * n + (j - 1)] = result; // i*n+j 줄에 최소 비용 저장된 도시 개수 저장하기
        }
    }
    return ans;//경로 값 반환
}

//플로이드-워셜
void floydWarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& path) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {//i->k->j 비교하기
            for (int j = 1; j <= n; j++) {
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist; //빠르면 값에 대해서 새로운 경로로 갱신하기
                    path[i][j] = path[k][j]; //경로(가장 마지막 정점) 저장
                }
            }
        }
    }
}

/**
 * graph: 플로이드-워셜 결과 행렬 그래프
 * path: 경료표. i->k->j로 갈 때 거치는 가장 마지막 정점. 즉, k와 j의 경로에 저장된 정점 <=> path[i][j] = path[k][j]
 * ans: 모든 (i, j)쌍의 역추적 결과값 저장
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 k->j의 중간 경로(path[k][j])로 갱신
 *    k로 갱신하는 게 아니라 path[k][j]로 갱신하는 이유는?
 *    만약 k->j의 경로가 k->t->j라면 최종 경로는 i->k->t->j
 *    바로 k로 갱신하면 t를 놓치고, 이러면 역추적을 할 수 없기 때문에 항상 j의 바로 전 경로를 저장해야 함
 */

int main() {
    int n, m, a, b, c; //도시수, 도착하는버스, 시작도시, 도착도시 ,비용

    //입력
    cin >> n >> m; //도시수, 도착하느 버스 개수 입력
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //도시수에 따른 그래프 배열 생성
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0));// 경로저장할 path배열 생성
    for (int i = 1; i <= n; i++) //자기 자신으로 가는 경로 초기화
        graph[i][i] = 0; //경로 초기화

    while (m--) {//버스 개수만큼
        cin >> a >> b >> c; //가는 방향 , 비용 입력
        graph[a][b] = min(graph[a][b], c); //단방향 그래프, 중복 간선 들어올 수 있음
        path[a][b] = a; //경로 초기화
    }

    //연산
    floydWarshall(n, graph, path); //플로이드 워셜로 최소 비용구하기
    vector<vector<int>> ans = allPath(n, path); //경로 배열

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << ((graph[i][j] == INF) ? 0 : graph[i][j]) << ' '; //갈수 없는 경우는 0출력하기
        cout << '\n'; //한줄 띄우기
    }
    for (int i = 0; i < ans.size(); i++) { //역추적 결과 있는 수만큼 반복
        int size = ans[i].size(); //i번째 역추적 개수
        cout << size << ' '; //역추적 개수먼저 출력 
        for (int j = size - 1; j >= 0; j--)
            cout << ans[i][j] << ' '; //i->j로가느 경로  출력해주기
        cout << '\n'; //한줄 띄우기
    }
    return 0;
}