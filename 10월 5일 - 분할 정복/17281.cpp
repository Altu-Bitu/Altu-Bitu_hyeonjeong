#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score, player;
vector<int> entry = { 0, 1, 2, 3, 4, 5, 6, 7, 8 }; //선수 순서
vector<vector<int>> board;

/**
 * 주자들 진루처리
 *
 * 1110 : 1, 2, 3루에 주자 존재
 * 0100 : 2루에 주자 존재
 * 1010 : 1, 3루에 주자 존재
 */
void running(int& run, int num) {//주자들 이동하는 함수
    run |= (1 << 0); //0번 플레이트에 타자 표시
    for (int i = (4 - num); i < 4; i++) { //홈까지 진루할 수 있는 주자들(베이스 4개에 대해서 이동하는것 표시)
        if (run & (1 << i)) { //주자가 있다면
            run &= ~(1 << i); //주자가 홈인 했기 때문에 플레이트를 비워줌
            score++;//점수는 하나 추가
        }
    }
    run = run << num; //주자들 이동
}

//idx 이닝 플레이
void playGame(int idx) {//인덱스 받고 이닝 플레이하기
    int out = 0, run = 0; //아웃카운트, 진루 상태
    while (out != 3) {//3아웃이면 종료하기
        int hit = board[idx][entry[player]]; //이번 주자의 결과
        if (!hit) //아웃
            out++;//아웃 개수 추가
        else //존재하는 모든 주자 진루
            running(run, hit);//쳤다면 이동하는 함수로
        player = (player + 1) % 9; //다음 선수(9명에 대해서 진행)
    }
}

int main() {
    int n, ans = 0;

    //입력
    cin >> n;//이닝수
    board.assign(n, vector<int>(9)); //9명으로 이루어진 선수들의 이닝에서 얻는 결과저장
    for (int i = 0; i < n; i++) {//이닝 수에 따라 저장하기
        for (int j = 0; j < 9; j++)//선수는 9명
            cin >> board[i][j]; //선수들이 얻는겨로가 저장(1,2,3,4,0)
    }

    //연산
    do {
        swap(entry[0], entry[3]); //1번 선수 4번 타자 되도록(문제조건)
        score = player = 0; //초기화
        for (int i = 0; i < n; i++) //각 이닝 플레이
            playGame(i);//이닝 플레이함수
        ans = max(ans, score);//결과는 가장 큰 값으로 저장
        swap(entry[3], entry[0]); //원래대로 복구(다시 게임 진행하기 위해)
    } while (next_permutation(entry.begin() + 1, entry.end()));//순열 이용해서  현재 인자에 대해 범위 만족하는 수열이면 다음 수열로 넘어가기

    //출력
    cout << ans;//가장 높은 점수를 출력
}