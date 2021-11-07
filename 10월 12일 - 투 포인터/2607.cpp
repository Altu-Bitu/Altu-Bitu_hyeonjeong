//추가제출
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26;//알파벳 사이즈

//알파벳별 등장횟수 저장
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0); //알파벳 숫자만큼 초기화 하고 있는 알파벳에 표시
    for (int i = 0; i < str.size(); i++)
        result[str[i] - 'A']++; //현재 알파벳 개수 저장
    return result; //알파벳 개수 표시한 배열 반환
}


int main() {
    int n, ans = 0;
    string source, target; //기본 단어, 비슷한 단어 찾을단어

    //입력
    cin >> n >> source;

    //연산
    vector<int> source_alpha = alphaMap(source); //현재 입력된 단어의 첨자 저장하기 위한 함수 호출
    while (--n) { //n번 진행
        cin >> target; //일치할 함수 찾기 위해 입력

        int diff = 0;//두 단어의 차이 저장
        vector<int> target_alpha = alphaMap(target); //비교할 단어의 첨자도 비교하기
        for (int i = 0; i < SIZE; i++) //두 단어의 차이
            diff += abs(source_alpha[i] - target_alpha[i]);//소스와 타겟의 첨자가 다르다면 그 차이는 1이더해질거임
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) //문자를 더하거나, 빼거나, 바꾸거나
            ans++; //차이가 1보다 작거나 차이가 이보다 작고 두단어 길이가 같은 경우에비슷한 단어라고 판단한다
    }

    //출력
    cout << ans; //비슷한 단어 개수 출력
}