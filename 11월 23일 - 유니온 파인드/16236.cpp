#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401;
typedef pair<int, int> ci;

pair<int, ci> nextPos(int n, int shark_size, ci& shark, vector<vector<int>>& board) { //상어의 위치이동
    int dr[4] = { -1, 1, 0, 0 }; //상하좌우 위치
    int dc[4] = { 0, 0, -1, 1 }; //상하좌우 위치

    int min_dist = INF; //일단 갈수있는 방향 무한으로 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    visited[shark.first][shark.second] = 1; //방문한 위치를 저장
    q.push(shark); //상어 간곳 저장
    while (!q.empty()) { //큐가 비지 않은 경우
        int row = q.front().first; //행에 저장하기
        int col = q.front().second; //열에 저장
        int dist = visited[row][col]; //현재 방문한 위치 거리 저장
        q.pop(); //저장된거 이용했으면 다음꺼로 진행

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue; //계속 진행
        for (int i = 0; i < 4; i++) { //반복진행
            int nr = row + dr[i];//다음 행 진행
            int nc = col + dc[i]; //다음 열 진행
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size) //물고기가없거나 방문했거나 이미 사이즈가 더 큰경우 끝내기
                continue;

            visited[nr][nc] = visited[row][col] + 1; //방문 기록 추가하기
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); //먹을수있는것 저장
                min_dist = visited[nr][nc]; //최소 거리에 저장하기
                continue; //계속진행하기
            }
            q.push({ nr, nc }); //큐에 먹을수있는 물고기의행과 열을 저장
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return { min_dist, {-1, -1} }; //갈곳이 없기때문에 -1로 저장

    sort(list.begin(), list.end(), [](const ci& p1, const ci& p2) { //정렬
        if (p1.first != p2.first) //첫번째 요소들의 대해 정렬
            return p1.first < p2.first; //내림차순 저장
        return p1.second < p2.second;// 내림차순
        });
    return { min_dist - 1, list[0] }; //최소거리 저장
}

int simulation(int n, pair<int, int>& shark, vector<vector<int>>& board) { //연산
    int ans = 0, size = 2, cnt = 0; //결과, 상어크기, 시간
    while (true) { //참인동안 진행하기
        pair<int, ci> result = nextPos(n, size, shark, board); //다음 위치에 있는상어의크기 저장
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break; //끝내기
        ans += result.first; //다음에 이동할 위치 저장
        cnt++;//시간 증가하기
        if (cnt == size) { //상어 크기 증가
            cnt = 0; //시간 초기화하기
            size++;//상어 크기 증가하기
        }

        //상어 이동
        ci pos = result.second; //다음 위치로 상어 이동
        board[shark.first][shark.second] = 0; //현재 판에서 상어의 위치의 크기를 초기화
        shark = pos; //상어위치 이동
    }
    return ans; //시간 반환하기
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n;
    pair<int, int> shark_pos; //상어 위치 지정하기

    //입력
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n)); //공간의 크기 주어짐
    for (int i = 0; i < n; i++) {//판 개수 만큼
        for (int j = 0; j < n; j++) { //판개수만큼
            cin >> board[i][j]; //물고기 위치 입력받기
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j); //상어 위치는 pair로 저장하기
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board); //물고기 잡아먹을수 있는시간 출력
}