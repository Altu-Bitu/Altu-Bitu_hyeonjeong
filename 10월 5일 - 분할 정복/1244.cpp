#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {
    for (int i = number; i <= n; i += number) //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i]; //배수에 있는 숫자들 0->1, 1->0 으로 바꾸기

    return switches;//스위치 벡터 return 
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {
    switches[number] = !switches[number];//여학생의 번호에 대한 스위치 바꾸기
    for (int i = 1; i < number; i++) {
        if ((number + i > n) || (switches[number - i] != switches[number + i])) //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break;//끝내기
        switches[number - i] = !switches[number - i];//왼쪽에 있는 값 스위치 반전
        switches[number + i] = !switches[number + i];//오른쪽에 있는 값 스위치 반전
    }

    return switches;//스위치 벡터 reutrn
}

/**
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m;
    int student, number;//성별, 받은 번호

    //입력
    cin >> n;//스위치개수
    vector<int> switches(n + 1, 0);//스위치 선언
    for (int i = 1; i <= n; i++)//스위치 상태 입력받기
        cin >> switches[i];//배열에 입력받기

    //입력 & 연산
    cin >> m;//학생수
    while (m--) {//학생수만큼 입력받기
        cin >> student >> number; //학생수, 학생이 가지고 있는 스위치 개수
        if (student == 1)//남학생이면
            switches = changeSwitchBoy(n, number, switches);//스위치개수, 스위치번호, 스위치 벡터 전달
        else//여학생이면
            switches = changeSwitchGirl(n, number, switches);//스위치 개수, 스위치번호, 스위치벡터 전달
    }

    //출력
    for (int i = 1; i <= n; i++) {//현재 스위치 상태 출력
        cout << switches[i] << ' ';//띄어쓰기 하나 포함해서 출력하기
        if (i % 20 == 0) //한 줄에 20개 입력 받기 만약 넘어가면 다음줄에 출력하기
            cout << '\n';//한 줄 띄기
    }
    return 0;
}