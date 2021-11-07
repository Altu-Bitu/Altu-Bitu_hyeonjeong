//추가제출
#include <iostream>
#include <vector>

using namespace std;

int ans, n, m; //가로,세로선언
vector<vector<int>> board; //테트로미노 보드 선언
int dr[4] = { -1, 1, 0, 0 };//이동 범위
int dc[4] = { 0, 0, -1, 1 }; //이동 범위

//board[row][col]을 가운데로 하는 +모양 만들기
int horn(int row, int col) {
    int cnt = 0, min_block = 1001, sum = board[row][col]; //입력이 1000을 안넘음, 현재 보드위치에 값을 저장해서 합구하도록함

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i]; //현재 행에서 이동 범위 변경하며 더하기
        int nc = col + dc[i]; //현재 열에서 이동 범위 변경하여 더하기

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) //범위를 벗어나면 무시
            continue;//범위 벗어나면 다시 돌아가기
        min_block = min(min_block, board[nr][nc]); //가장자리 블럭 중 값이 가장 작은 블럭
        sum += board[nr][nc]; //범위 이동한 블록에 있는 값을 더해가기
        cnt++; //몇 번 진행했는지 숫자 세기
    }

    if (cnt < 3) //가능한 가장자리가 최소 3개 이상이어야 함
        return 0;//3개보다 작으면 조건 만족못하므로 0 return
    if (cnt == 3) //ㅗㅏㅜㅓ
        return sum; //합을 리턴
    //+
    return sum - min_block; //위에 경우 다 아닌경우 +인경우에 값 리턴
}

//한붓 그리기가 가능한 블럭들 백트래킹 탐색
void backtracking(int row, int col, int cnt, int sum) {
    if (cnt == 4) { //기저조건 : 4개의 블럭을 탐색함
        ans = max(ans, sum); //기저 조건인 경우 가장 최대값 저장
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];//현재 행에서 이동 범위에 대해서 진행
        int nc = col + dc[i]; //현재 열에서 이동 범위에서 진행

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || !board[nr][nc]) //범위를 벗어나거나, 이미 방문했다면
            continue;
        int save = board[nr][nc]; //현재 보드에서 이동해있는 위치에 있는 숫자값 저장
        board[nr][nc] = 0; //저장한 값은 0으로 만들어서 다시 안 저장하도록
        backtracking(nr, nc, cnt + 1, sum + save); //백트래킹으로 다시 반복
        board[nr][nc] = save; //돌아왔을 때 값을 저장한다.
    }
}

int main() {
    //입력
    cin >> n >> m;//세로, 가로 입력받기
    board.assign(n, vector<int>(m, 0));//2차원 배열 초기화
    for (int i = 0; i < n; i++) { //입력 받기
        for (int j = 0; j < m; j++)
            cin >> board[i][j];//가로 세로에 대한 값 입력받기
    }

    //연산
    for (int i = 0; i < n; i++) {//세로
        for (int j = 0; j < m; j++) { //가로
            ans = max(ans, horn(i, j)); //보라색 블럭 처리 (백트래킹 불가능)
            int save = board[i][j];  //숫자누적

            board[i][j] = 0; //현재 저장한부분은 0으로
            backtracking(i, j, 1, save); //나머지 모양 처리
            board[i][j] = save; //숫자 누적 (최댓값 구하기)
        }
    }

    //출력
    cout << ans; //구한 최대값 출력하기
}