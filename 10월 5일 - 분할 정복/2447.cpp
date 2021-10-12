#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board;

void star(int row, int col, int size) { //행,열,사이즈 마다 재귀함수돌기
    //Conquer : size의 크기가 1
    if (size == 1) {//기저조건
        board[row][col] = '*';//현재 행과 열 별찍기
        return;
    }

    //Divide : 9등분 하는데, 가운데 부분에 대해선 함수 호출하지 않음
    int next_size = size / 3;//3의 패턴으로 별 찍어주기(가운데 제외)
    for (int i = 0; i <= next_size * 2; i += next_size) {//별 3개찍고 넘어가야하므로 다음 크기의 2배만큼
        for (int j = 0; j <= next_size * 2; j += next_size) {
            if (i == next_size && j == next_size) //가운데 부분
                continue;//가운데 부분은 별찍지 않음
            star(row + i, col + j, next_size);//다음 별 찍을때 다음 행과 열로 가서 찍도록하기
        }
    }
}

/**
 * ***   (0, 0) (0, 1) (0, 2)
 * * *   (1, 0) (1, 1) (1, 2)
 * ***   (2, 0) (2, 1) (2, 2)
 *
 * 1. 가운데 부분에 대해서만 함수를 호출하지 않으면 됨
 * 2. 왼쪽 맨위 좌표를 (r, c)라 하고, 배열의 크기를 size라고 할 때, 가운데 부분은 (r+(size/3), c+(size/3))
 * 3. size가 1이될 때까지 나누기
 */
int main() {
    int n;

    //입력
    cin >> n;
    board.assign(n, vector<char>(n, ' '));//이차원배열 할당

    //연산
    star(0, 0, n);//별만들기

    //출력
    for (int i = 0; i < n; i++) {//행
        for (int j = 0; j < n; j++)//열
            cout << board[i][j];//별 찍은 부분 출력
        cout << '\n';//다음 행
    }
}