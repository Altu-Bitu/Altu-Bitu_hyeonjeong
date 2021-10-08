#include <iostream>
#include <string>
#include <deque>

using namespace std;

//k개의 수 지워서 큰 수 만드는 함수
string makeBigNum(string number, int l, int k) {
    deque<int> dq; //덱 선언해서 앞에와 뒤에서 지우고 삽입 가능하도록 함
    int cnt = 0; //몇 번 지웠는지 입력 받음
    for (int i = 0; i < l; i++) {
        while (!dq.empty() && dq.front() < number[i] - '0' && cnt < k) { //덱에 숫자 있고 지울 숫자가 더 작고 k번 안채운경우에 진행한다
            dq.pop_front(); //dq.front() 지우기
            cnt++; //지워진 숫자 증가 (k번 진행)
        }
        dq.push_front(number[i] - '0'); //이번 입력 삽입
    }
    while (dq.size() > (l - k)) //충분히 지우지 못했다면 앞에서부터(자릿수가 작은 숫자) 지우기
        dq.pop_front();//k만큼 다 못지우면 자릿수 작은거 지우기

    string answer = "";//정답 변수 선언
    while (!dq.empty()) { //큰 자릿수부터 정답에 추가, 덱에 숫자가 없을 때 까지 진행한다
        answer += (dq.back() + '0'); //큰 수 부터 answer에 추가
        dq.pop_back(); //dp에 있는 것은 큰 거 부터 제거해주기
    }
    return answer;//가장 큰 수 return
}


string solution(string number, int k) {
    return makeBigNum(number, number.length(), k);//만들 수, 숫자 크기, 몇번 진행할지 전달해주기
}

int main() {
    string number = "1924"; //만들 수 선언
    int k = 2; //두 자리 수 만들기

    //연산 &출력
    cout << solution(number, k); //가장 큰숫자 출력

    return 0;
}