#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>>& graph, vector<vector<int>>& table) { //모든 정점 두개 사이에서의 최단경로 구해주는 플로이드 워셜 이용
    for (int k = 1; k <= n; k++) { //중간에 지나갈 k로
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= n; j++) {
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist; //더 빠른 경로 저장하기
                    table[i][j] = table[i][k]; //더 빠르면 전에온 경로 저장해두기
                }
            }
        }
    }
}

/**
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 16을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */
int main() {
    int n, m, s, d, c;

    //입력
    cin >> n >> m; //집하장 개수, 집하장 경로의 개수
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));// 집하장 개수에 대해서 그래프 생성
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0)); //저장해둘 경로 배열
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0; //우선 다 0으로 초기화 시키기

    while (m--) { //무방향 그래프
        cin >> s >> d >> c; //두 집하장의 번호와 필요한시간이 순서대로 주어짐
        //간선 정보
        graph[s][d] = graph[d][s] = c;  //간선 정보 저장

        //경로 정보
        table[s][d] = d; //집하장 번호에 대해 행 번호로 경로 저장
        table[d][s] = s; //집하장 경로에 대해 열 번호로 저장
    }

    //연산
    floydWarshall(n, graph, table); //플로이드 워셜로 비교하기

    //출력
    for (int i = 1; i <= n; i++) { //그래프 출력 행
        for (int j = 1; j <= n; j++) { //열
            if (i == j)
                cout << "- "; // i=j이면 -로 출력
            else
                cout << table[i][j] << ' ';// 테이블에 저장된 정보 출력하기
        }
        cout << '\n';// 한줄 띄기
    }
}