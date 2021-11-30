#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; //루트저장하기 위해 사용

//Find 연산
int findParent(int node) {//부모노드 찾기
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node; //현재 노드 반환하기
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //x의 부모노드 저장
    int yp = findParent(y); //y의 부모노드 저장

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //새로운 루트xp로 저장하기
        parent[yp] = xp;  //새로운 루트에 저장
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp]; //새롱누 루트 yp로
        parent[xp] = yp; //새로운 루트에 저장
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cmd, a, b; //원소의개수, 연산의 개수, 합집합

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1); //루트노드 저장할곳
    while (m--) { //연산개수만큼 진행
        cin >> cmd >> a >> b; //0ab형태로 입력받기

        //연산
        if (cmd == 0) { //유니온
            unionInput(a, b); //합집합연산
        }
        if (cmd == 1) { //파인드
            if (findParent(a) == findParent(b))//부모노드가 같으면
                cout << "YES\n"; //YES 출력
            else //아니면
                cout << "NO\n"; //NO출력
        }
    }
}