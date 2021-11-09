//추가제출

#include <iostream>
#include <map>

using namespace std;
typedef pair<int, int> ci; //좌표 저장할공간
const int SIZE = 8; //움직이는 전체정보 초기화

//움직임 정보
map<string, int> direction = { {"L",  0},  //상
                              {"R",  1},  //하
                              {"B",  2},  //좌
                              {"T",  3},  //우
                              {"LT", 4},  //우상향
                              {"LB", 5},  //좌상향
                              {"RT", 6},  //우하향
                              {"RB", 7} }; //좌하향

string pointToString(ci point) {
    string ans; //위치 반환할것
    ans = (point.first + 'A'); //킹위치를 반환(다시 문자로)
    ans += (point.second + '1'); //돌위치 문자로 변환해서
    return ans; //출력할값 리턴
}

pair<ci, ci> moveKing(string move, ci point_k, ci point_r) {
    //상, 하, 좌, 우, 우상향, 좌상향, 우하향, 좌하향
    int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 }; //방향
    int dc[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };//방향
    int d = direction[move]; //방향 인덱스 저장

    int king_nr = point_k.first + dr[d]; //킹위치에서 x좌표 이동
    int king_nc = point_k.second + dc[d]; //킹위치에서 y좌표 이동
    if (king_nr < 0 || king_nr >= SIZE || king_nc < 0 || king_nc >= SIZE) //킹이 범위를 벗어나는 경우
        return { point_k, point_r }; //킹위치와 돌위치 현재정보 반환하기

    if (king_nr != point_r.first || king_nc != point_r.second) //킹이 움직이는 방향에 돌이 없는 경우
        return { {king_nr, king_nc}, point_r }; //반환하는 경우라 현재 킹위치로 새롭게 반환하기

    //돌이 있다면
    int rock_nr = point_r.first + dr[d]; //돌있어서 돌위치도 이동
    int rock_nc = point_r.second + dc[d]; //돌의 y좌표 이동
    if (rock_nr < 0 || rock_nr >= SIZE || rock_nc < 0 || rock_nc >= SIZE) //범위를 벗어나면
        return { point_k, point_r }; //현재 범위를 벗어난경우라서 현재 돌과 킹위치를 반환

    return { {king_nr, king_nc}, {rock_nr, rock_nc} }; //모든 경우 아니라면 이동한 킹과 돌위치를 반환해주기
}


int main() {
    string king, rock, move; //킹의위치, 돌의위치, 어떻게 움직이는지
    int n; //움직이는 횟수

    //입력 & 연산
    cin >> king >> rock >> n; //킹의위치, 돌의위치, 움직이는 횟수 입력받기
    ci point_k = { king[0] - 'A', king[1] - '1' }; //초기 킹 위치
    ci point_r = { rock[0] - 'A', rock[1] - '1' }; //초기 돌 위치
    pair<ci, ci> point = { point_k, point_r }; //킹위치, 돌위치를 변수에 저장
    while (n--) {
        cin >> move; //움직일 곳 입력 받기
        point = moveKing(move, point.first, point.second); //움직이는정보, 킹위치, 돌위치를 전달
    }

    //출력
    cout << pointToString(point.first) << '\n' << pointToString(point.second) << '\n'; //킹과 돌의 위치를 출력
    return 0;
}