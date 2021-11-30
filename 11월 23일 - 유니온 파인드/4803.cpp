#include <iostream>
#include <vector>

using namespace std;

vector<bool> cycle; //간선지나갓는지
vector<int> parent; //루트노드 저장

//Find 연산
int findParent(int node) { //루트노드 찾기
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //음수면 반환하기
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모노드 찾기
    int yp = findParent(y); //y의 부모노드 찾기

    if (xp == yp) { //같은 집합에 있다면 유니온 할 수 없음
        cycle[xp] = true; //같은 노드면 합칠수없음
        return;
    }
    if (cycle[xp] || cycle[yp]) //둘 중 하나라도 사이클이 있으면 표시
        cycle[xp] = cycle[yp] = true; //사이클 있는지 여부
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //더작은 루트에대해서 합치기
        parent[yp] = xp; //yp도 루트노드 변경
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp]; //xp의 루트노드 바꾸기
        parent[xp] = yp; //yp로 루트노드 저장
    }
}

int cntTree(int n) {
    int cnt = 0; //트리개수
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0 && !cycle[i]) //루트 정점인데 사이클도 없을 때
            cnt++; //사이클 없는 트리개수 더해주기
    }
    return cnt; //트리개수반환
}

void printResult(int num, int cnt) {
    cout << "Case " << num;
    if (cnt == 0) //트리개수 0인경우
        cout << ": No trees.\n"; //트리없음을 의미
    else if (cnt == 1) //트리개수 한개이면
        cout << ": There is one tree.\n"; //한개인 문구 출력
    else //더많으면 
        cout << ": A forest of " << cnt << " trees.\n"; //개수 출력하기
}

int main() {
    int n, m, a, b, test_case = 0;

    while (true) {
        test_case++; //여러개의 테스트 케이스 진행

        //입력
        cin >> n >> m;
        if (n == 0 && m == 0) //종료 조건
            break;
        parent.assign(n + 1, -1); //루트 저장할노드
        cycle.assign(n + 1, false); //사이클, 지나가는 간선
        while (m--) { //무방향 그래프
            cin >> a >> b; //트리 주어지기
            unionInput(a, b); //합치기
        }

        //연산
        int tree_cnt = cntTree(n); //트리개수 구하기

        //출력
        printResult(test_case, tree_cnt); //테스트 케이스와 트리개수에 대해서 출려ㄱ값 구하기
    }
}