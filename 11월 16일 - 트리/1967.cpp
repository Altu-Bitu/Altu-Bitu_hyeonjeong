#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci dfs(int node, int parent, vector<vector<ci>>& graph) {
    int pos = node, len = 0; //지름을 구성하는 노드 중 하나, 그 노드까지의 거리
    for (int i = 0; i < graph[node].size(); i++) { //트리의 사이즈만큼 반복
        int next_node = graph[node][i].first; //다음 노드에는 현재 노드의 기존거리 저장
        if (next_node == parent) //그 부모노드와 같다면 계속진행
            continue;

        ci dfs_search = dfs(next_node, node, graph); //자식 노드에 대해 dfs 탐색
        if (graph[node][i].second + dfs_search.first > len) { //기존 거리보다 길다면 갱신
            len = graph[node][i].second + dfs_search.first; //길이 갱신 시키기
            pos = dfs_search.second; //위치 다음 노드위치로 
        }
    }
    return { len, pos }; //길이와 위치를 반환하기
}

/**
 * 1. 지름을 이루는 두 점은 모두 리프 노드
 * 2. 임의의 한 노드에서 가장 멀리 있는 노드(리프 노드)는 지름을 이루는 노드 중 하나
 * 3. 지름을 이루는 노드에서 가장 멀리 있는 노드는 지름을 이루는 다른 노드
 *
 * 부모->자식의 방향만 저장하면 리프 노드에서 다른 리프 노드로 탐색할 수 없으므로 무방향 그래프로 저장
 */
int main() {
    int n, p, c, w;

    //입력
    cin >> n; //노드의 개수 입력
    vector<vector<ci>> graph(n + 1, vector<ci>(0));//트리 가중치와 함께 저장할 배열 만들기
    for (int i = 1; i < n; i++) { //무방향 그래프로 만들기
        cin >> p >> c >> w;//간선 정보 입력
        graph[p].emplace_back(c, w); //간선 정보에 대한 저장
        graph[c].emplace_back(p, w); //x, y바꿔서 정보 저장(무방향이라서)
    }

    //연산
    ci first_node = dfs(1, -1, graph); //지름을 구성하는 노드 하나 찾기
    ci second_node = dfs(first_node.second, -1, graph); //지름을 구성하는 다른 노드 찾기
    
    //출력
    cout << second_node.first; ///트리지름 출력하기
}