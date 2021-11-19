#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19; //바둑판 사이즈

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>>& board) {
    return r >= 0 && r < SIZE&& c >= 0 && c < SIZE&& board[r][c] == stone; //범위 확인하고, 돌의 종류 유효하면 1반환
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>>& board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = { 0, 1, 1, -1 }; //방향 저장
    int dc[4] = { 1, 0, 1, 1 }; //방향 저장

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    bool is_six = promising(r - dr[d], c - dc[d], stone, board); //

    int cnt = 0;
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++; // 조건 만족하면 카운트 더하기
        r += dr[d]; //다음 x축 위치
        c += dc[d]; //다음 y축 위치
    }
    return cnt == 5 && !is_six;
}

bool isEnd(int r, int c, vector<vector<int>>& board) { //이긴사람 결정하기
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) //이어지는 돌있는지 확인하는 함수
            return true; //있으면 1 리턴해서 이긴사람 결정
    }
    return false; //없으면 0 값을 반환하기
} 

/**
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는 경우 : (r, c) 왼쪽에 같은 돌이 있는 경우
 */
int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); //바둑판

    //입력
    for (int i = 0; i < SIZE; i++) { //바둑판 입력하기
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j]; //검은 바둑알은 1, 흰 바둑알은 2, 알이 없으면 0으로 입력하기
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) //돌이 없음
                continue; //다시 돌아가기
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;  //이긴 말과 가로줄번호, 세로줄 번호 출력
                return 0;
            }
        }
    }
    cout << 0;//아직 승부 안나면 0출력
}