//추가제출

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //pair로 선언
const int SIZE = 100 + 1; //격자 사이즈

//우, 상, 좌, 하
int dy[4] = { 0, -1, 0, 1 }; //좌표 저장
int dx[4] = { 1, 0, -1, 0 }; //좌표 저장

//크기가 1x1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것이 개수 구하기
int cntSquare(vector<vector<bool>>& board) {
    int ans = 0; //개수 저장할 변수
    for (int i = 0; i < SIZE - 1; i++) { //전체 격자 사이즈만큼 돌기
        for (int j = 0; j < SIZE - 1; j++) {
            if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1]) //정사각형 이루는 격자 만족하면 드래곤 커브 개수 올리기
                ans++; //드래곤 커브의일부인 개수 추가
        }
    }
    return ans; //총 드래곤 커브 일부인 것들의 개수
}

ci makeDragonCurve(vector<vector<bool>>& board, vector<int>& direc, ci point) {
    int size = direc.size(); //그 전 세대까지의 방향 정보
    for (int i = size - 1; i >= 0; i--) {
        int new_direc = (direc[i] + 1) % 4; //현재 시작 점의 방향
        point = { point.first + dy[new_direc], point.second + dx[new_direc] }; //현재 끝 점
        board[point.first][point.second] = true; //지나간 격자는 표시해주기
        direc.push_back(new_direc); //현재 갱신된 방향정보 넣어주기
    }
    return point; //현재 위치 반환
}



int main() {
    int n, x, y, d, g;

    //입력 & 연산
    cin >> n;
    vector<vector<bool>> board(SIZE, vector<bool>(SIZE, false)); //100x100 격자
    while (n--) {
        cin >> x >> y >> d >> g; //시작점(x,y), 시작방향, 세대
        vector<int> direc; //세대의 방향 정보 저장 및 보존하는 벡터
        ci end_point = { y + dy[d], x + dx[d] }; //0세대 끝점 이동 좌표 표현
        board[y][x] = board[end_point.first][end_point.second] = true; //0세대 시작점, 끝점 초기화
        direc.push_back(d); //0세대 방향 삽입
        while (g--) { //각 세대마다 드래곤 커브 만들기, 입력받은 개수만큼 만들기
            end_point = makeDragonCurve(board, direc, end_point);  //드레곤 커브 만들기(반환값은 끝점 저장)
        }
    }

    //출력
    cout << cntSquare(board) << '\n'; //드래곤 커브의 일부인 것의 개수 출력
    return 0;
}