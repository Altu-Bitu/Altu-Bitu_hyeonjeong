#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) { //루트 정점찾기
    if (parent[node] == -1) //루트 정점
        return node; //루트 정점이면 반환
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionGate(int gate) { //현재 게이트와 가능한 게이트 union연산
    int possible_gate = findParent(gate); //도킹 가능한 게이트
    if (possible_gate == 0) //도킹 불가
        return false; //도킹 불가 반환
    parent[possible_gate] = possible_gate - 1; //도킹 처리
    return true;//도킹 가능 반환
}

/**
 * 그리디
 * 1. 1 ~ gi 까지의 게이트 중 어떤 게이트에 도킹해야 할까?
 * 2. 1번 게이트부터 도킹한다면... g1 = 3, g2 = 1인 경우 1대의 비행기만 도킹할 수 있음
 * 3. gi번 게이트부터 도킹한다면... g1 = 3, g2 = 1인 경우 2대의 비행기 모두 도킹할 수 있음
 * -> gi번 게이트부터 1번 게이트까지 가능한 게이트를 찾으면 바로 도킹 (그리디)
 *
 * 유니온 파인드
 * 1. 만약 1번 게이트가 비어있고, 2 ~ 1,000번 게이트가 도킹되어 있으며 gi = 1,000인 입력이 들어왔을 때...
 * 2. 1,000번 게이트부터 하나하나 거슬러 올라가며 1번 게이트까지 가는 것은 비효율적 (시간초과)
 * 3. 도킹할 때마다 이번에 도킹한 게이트의 바로 이전 게이트를 집합의 루트 정점으로 만들어 바로 접근할 수 있도록 설정
 */
int main() {
    int g, p, gi; //게이트수. 비행기수,게이트개수

    //입력
    cin >> g >> p; //게이트수, 비행기수 입력
    parent.assign(g + 1, -1); //게이트 개수만큼 할당
    for (int i = 0; i < p; i++) {
        cin >> gi; //게이트번호 입력

        //연산
        if (!unionGate(gi)) { //도킹 불가능
            cout << i; //현재 개수 출력
            return 0;
        }
    }

    //출력
    cout << p; //최대 비행기 개수 출력
}