#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 20;
const int INF = 10e8;

int n;
int answer = INF;//능력치 최소값
int power[SIZE][SIZE]; //능력치 값
bool is_start[SIZE];//스타트,링크 인원수 체크
int start[SIZE], link[SIZE]; //스타트와 링크 팀에 속하는 사람

//각 팀의 능력치를 계산하는 함수
int calcPower(int arr[], int size) {//팀배열, 팀인원수
    int result = 0;

    //모든 Sij의 합
    for (int i = 0; i < size; i++) {//팀인원수만큼 능력치 더하기
        for (int j = i + 1; j < size; j++)
            result += power[arr[i]][arr[j]] + power[arr[j]][arr[i]];//인덱스 ij인 경우와 ji인 경우 능력치 값에 더하기
    }
    return result;
}

void backtracking(int cnt, int st) {
    if (cnt == n) //팀인원 채운경우(기저조건)
        return;
    if (cnt > 0) { //최소 1명이 팀에 있어야 함
        int idx = 0;//인덱스
        for (int i = 0; i < n; i++) {//팀 배정하기
            if (!is_start[i]) //스타트 팀이 아니라면->링크팀(스타트 팀으로 꾸려나가기)
                link[idx++] = i;//링크팀에 인원추가
        }
        int diff_value = abs(calcPower(link, idx) - calcPower(start, cnt)); //두 팀의 능력치 차이(절대값으로 음수인경우도 양수로)
        answer = min(answer, diff_value); //차이의 최솟값 저장
    }
    for (int i = st; i < n; i++) {
        is_start[i] = true; //링크 팀에 속하는 사람 추리기 위해 스타트 팀원 체크
        start[cnt] = i; //스타트 팀에 배치
        backtracking(cnt + 1, i + 1);//백트래킹(재귀)
        if (i == 0) //1번 사람이 링크 팀이 됨 -> 어차피 스타트 팀이었던 경우와 값 같음
            return;// 스타트 팀이었던 구성이 링크 팀 된 경우도 차이값은 같기 때문에
        is_start[i] = false;//다시 스타트 팀 초기화
    }
}



int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> power[i][j]; //능력치 입력받기
        }
    }

    //연산
    backtracking(0, 0);

    //출력
    cout << answer << '\n';

    return 0;
}