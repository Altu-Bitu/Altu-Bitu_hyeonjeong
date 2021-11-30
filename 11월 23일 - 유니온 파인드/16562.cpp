#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node;//현재 노드 출력하기
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모노드 저장
    int yp = findParent(y);//y의 부모노드 저장

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;
    if (parent[xp] > parent[yp]) //새로운 루트 xp
        parent[yp] = xp; // 새로운 루트로 저장하기
    else //새로운 루트 yp
        parent[xp] = yp; //새로운 루트 저장
}

int friendshipCost(int n) { //친구비용구하기
    int sum = 0; //친구비용 합
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) //루트 정점이라면
            sum += -parent[i]; //부모노드의 비용 저장하기(음수로 저장되어있는거 반대로)
    }
    return sum; //친구비용 반환하기
}

int main() {
    int n, m, k, v, w, cost;

    //입력
    cin >> n >> m >> k; //학생수, 친구관계수, 돈
    parent.assign(n + 1, 0); //학생의 루트학생 저장하기위해 할당
    for (int i = 1; i <= n; i++) {
        cin >> cost; //비용 저장
        parent[i] = -cost; //루트 정점에 필요한 친구비(음수)를 저장
    }

    //연산
    while (m--) {
        cin >> v >> w; //서로 친구인 친구 입력받기
        unionInput(v, w); //친구 합치기
    }

    int ans = friendshipCost(n); //친구비용 최소비용 구하기
     
    //출력
    if (ans <= k)
        cout << ans; //친구비용 출력하기
    else
        cout << "Oh no"; //친구를 사귈수없음
}