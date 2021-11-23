#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>>& board) {
    //상, 우, 하, 좌
    int dr[4] = { -1, 0, 1, 0 };//상, 우, 하, 좌의 x좌표
    int dc[4] = { 0, 1, 0, -1 };//상, 우, 하, 좌의 y좌표

    int step = 0, ans = 0; //회전카운트,결과 값 저장할 배열
    while (true) { //참인 동안
        if (board[r][c] == 0) { //빈경우
            board[r][c] = 2; //청소했다고 표시해주기
            ans++; //청소한 상태 개수 증가
        }

        if (step == 4) {//제자리로 돌아온경우
            if (board[r - dr[d]][c - dc[d]] == 1) //벽인 경우
                return ans; //현재 청소 개수 반환
            r -= dr[d]; //방향 이동
            c -= dc[d];// y 방향 이동
            step = 0; //회전카운트 0으로
        }
        else {
            d = (d + 3) % 4; //4가지 방향에 대해서 이동할거 저장
            if (board[r + dr[d]][c + dc[d]]) { //이동방향만큼 움직이기
                step++; //회전한것에 대한 횟수 증가
                continue; //계속 진행
            }
            r += dr[d]; //방향 더해주기
            c += dc[d]; //방향 더해주기
            step = 0; //회전 원점으로 돌아왔음을 의미
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d;

    //입력
    cin >> n >> m >> r >> c >> d; //세로, 가로, 칸의 좌표. 바라보는방향
    vector<vector<int>> board(n, vector<int>(m, 0)); //n*m 배열 만들기
    for (int i = 0; i < n; i++) { //행
        for (int j = 0; j < m; j++) {//열
            cin >> board[i][j]; //좌표에 대해방향 입력받기
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board); //로봇 청소기가 청소하는 칸 개수 구하기
    return 0;
}