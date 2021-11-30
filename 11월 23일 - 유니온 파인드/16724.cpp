#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> parent;

//Find 연산
int findParent(int m, int row, int col) { //루트노드 찾는 연산
    if (parent[row][col] < 0) //루트 정점
        return row * m + col; //루트정점이면 행과 열 연산으로 반환
    int pos = parent[row][col]; //현재 행과 열의 위치 저장
    return parent[row][col] = findParent(m, pos / m, pos % m); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int m, int r1, int c1, int r2, int c2) {
    int xp = findParent(m, r1, c1); //부모노드 찾기
    int yp = findParent(m, r2, c2); //다음노드의 부모노드 찾기
    int xr = xp / m, xc = xp % m;//xp의 연산
    int yr = yp / m, yc = yp % m;//yp의 연산

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return;
    if (parent[xr][xc] < parent[yr][yc]) { //새로운 루트 xp
        parent[xr][xc] += parent[yr][yc]; //새로운 루트로 union연산 하기
        parent[yr][yc] = xp; //xp로 부모노드 변경
    }
    else { //새로운 루트 yp
        parent[yr][yc] += parent[xr][xc]; //yp로 부모노드 변경
        parent[xr][xc] = yp;// yp 노드 저장하기
    }
}

void unionPair(int n, int m, vector<vector<char>>& board) {//유니온 파인드 연산
    map<char, pair<int, int>> dir; //맵을 사용해 각 문자를 방향에 대입
    dir['U'] = { -1, 0 }; //방향 설정 위방향
    dir['D'] = { 1, 0 }; //아래방향
    dir['L'] = { 0, -1 }; //왼쪽방향
    dir['R'] = { 0, 1 }; //오른쪽 방향

    for (int i = 0; i < n; i++) {//행개수만큼 반복
        for (int j = 0; j < m; j++) {//열개수만큼 반복
            pair<int, int> d = dir[board[i][j]]; //유니온 될 좌표가 있는 방향
            unionInput(m, i, j, i + d.first, j + d.second);//루트union하며 저장하기 
        }
    }
}

int cntZone(int n, int m) { //safezone 개수 세기
    int cnt = 0; //집합의 개수 세기
    for (int i = 0; i < n; i++) {//행개수만큼 진행
        for (int j = 0; j < m; j++) { //열개수만큼 진행
            if (parent[i][j] < 0) //음수로 저장된게 부모노드
                cnt++; //safezone개수 카운트하기
        }
    }
    return cnt; //safezone 개수반환
}

/**
 * 1. 화살표를 통해 접근할 수 있는 좌표 = 하나의 집합으로 연결된 좌표
 * 2. 같은 집합 안에 속해있는 좌표들은 모두 언젠가 방문 가능한 좌표
 * 3. 서로소인 각 집합에서 한 개씩의 좌표만 SAFE ZONE이어도 모든 회원들이 안전할 수 있음
 * 4. 2차원 좌표를 int 값 하나로 저장하기 위해 모든 행을 일렬로 나열하는 방법 사용 (각 좌표에 pair 변수를 저장해 부모를 표시할 수도 있음)
 */
int main() {
    int n, m;
    string input; 

    //입력
    cin >> n >> m; //지도 행의수, 열의수 입력
    vector<vector<char>> board(n, vector<char>(m)); //지도 정보 저장할 배열 선언
    parent.assign(n, vector<int>(m, -1)); //루트노드 저장할 배열 
    for (int i = 0; i < n; i++) {
        cin >> input; //입력받기
        for (int j = 0; j < m; j++)
            board[i][j] = input[j]; //지도에 나가는 방향 저장하기
    }

    //연산
    unionPair(n, m, board); //유니온파인드로 연산

    //출력
    cout << cntZone(n, m); //safezone 개수 반환하기
}