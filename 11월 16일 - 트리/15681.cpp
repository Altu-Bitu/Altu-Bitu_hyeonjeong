#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt;

int treeDp(int cur, vector<vector<int>>& graph) {
    if (subtree_cnt[cur] != -1) //이미 탐색했던 상태
        return subtree_cnt[cur];  //탐색했으면 현재 서브트리 반환

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0; //정점 0으로 초기화
    int node = 1; //노드는 1로
    for (int i = 0; i < graph[cur].size(); i++) //트리개수만큼 진행하기
        node += treeDp(graph[cur][i], graph); //노드에 누적으로 쿼리에 대해 더하기
    return subtree_cnt[cur] = node; //현재 서브트리값에 노드 값 저장
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 계산
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input; //정점수, 루트번호, 쿼리수, 간선 정보

    //입력
    cin >> n >> r >> q;//정점수, 루트번호, 쿼리수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //입력받은 정점수만큼 배열 만들기
    subtree_cnt.assign(n + 1, -1); //서브트리 배열 생성

    while (--n) { //무방향 그래프
        cin >> u >> v; //간선 정보 저장
        graph[u].push_back(v); //u,v 입력받고 저장
        graph[v].push_back(u); //무방향이니까 반대도 저장
    }

    //연산
    treeDp(r, graph); //트리 DP 연산진행

    //출력
    while (q--) { //쿼리수만큼 진행
        cin >> input;  //쿼리로 입력값 주어진다
        cout << subtree_cnt[input] << '\n'; //입력값에 대한 쿼리 답을 구해준다
    }
}