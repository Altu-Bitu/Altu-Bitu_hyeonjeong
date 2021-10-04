#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

ci dir[4] = { {0,  1},  //우
             {-1, 0},  //상
             {0,  -1}, //좌
             {1,  0} }; //하

//게임을 진행하는 함수
int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
    //뱀 초기화
    deque<ci> snake;//뱀변수
    snake.push_front(ci(0, 0));//먼저 초기상태
    board[0][0] = 1;//뱀위치에 표시

    int t = 0, head = 0; //시간, 뱀의 머리 방향
    while (true) {
        t++;//시간
        //뱀의 머리가 위치하게될 칸
        int nr = snake.front().first + dir[head].first;//뱀의 머리,뱀의 머리방향
        int nc = snake.front().second + dir[head].second;//뱀의 꼬리방향,위치

        //게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1)//꼬리와 머리가 멱에 부딪히거나,서로 부딪힌경우
            break;//종료

        if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            board[snake.back().first][snake.back().second] = 0;//위치 이동하기
            snake.pop_back();//꼬리 있던 칸 비어주기
        }

        //뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        snake.push_front(ci(nr, nc));//사과있으면 몸길이 늘려주기
        board[nr][nc] = 1;//자신의 몸 늘리기

        //이번에 방향을 변환하는지 확인
        if (cmd[t] == 'L') //왼쪽 회전
            head = (head + 1) % 4;//좌우상하 4가지니까 %4로 
        if (cmd[t] == 'D') //오른쪽 회전
            head = (head + 3) % 4;//오르쪽은 세번전환
    }
    return t;
}

int main() {
    int n, k, row, col, l, x;//보드이 크기, 사과의 개수, 열과행, 방향 변환 횟수,초
    char c;//오른쪽or왼쪽

    //입력
    cin >> n >> k;
    vector<vector<int>> board(n, vector<int>(n));//보드
    for (int i = 0; i < k; i++) {
        cin >> row >> col;//사과 있는 열과 행 입력
        board[row - 1][col - 1] = 2; //사과 표시
    }
    cin >> l;//방향변환 횟수
    map<int, char> cmd;//(초,방향)
    for (int i = 0; i < l; i++) { //회전 정보
        cin >> x >> c;//입력받기
        cmd[x] = c;//x초 끝나고 방향 전환
    }

    //연산 & 출력
    cout << playGame(n, board, cmd);//도스게임시작
}