#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * 맵, 셋에서 다루었던 '추월' 문제와 어떤 점에서 다른지 생각해보세요
 */
int main() {
    int n, ans = 0;//해전의 개수
    string input;//입력받을것
    map<string, int> seq; //각 입력과 입력의 인덱스

    //입력
    cin >> n;
    vector<string> answer(n); //현우가 적은 정답
    for (int i = 0; i < n; i++) {
        cin >> input;//정답 입력
        seq[input] = i;//정답의 인덱스
    }
    for (int i = 0; i < n; i++)
        cin >> answer[i];//현우의 정답 입력 받기

    //연산
    //모든 n(n-1)/2개의 쌍에서 올바른 순서로 적힌 답안 찾기
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (seq[answer[i]] < seq[answer[j]]) //두 답안의 상대적인 관계가 맞음
                ans++;//현우가 적은 정답에서 순서 관계가 일치하면 답안 점수 1점 추가
        }
    }

    //출력
    cout << ans << '/' << n * (n - 1) / 2; //답안 개수 출력
}