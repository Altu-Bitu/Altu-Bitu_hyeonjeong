#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

int k;
bool is_find;
vector<char> op(SIZE); //부등호
vector<int> arr(SIZE), num(SIZE);
vector<bool> check(SIZE);//체크

//수열을 문자열로 바꾸는 함수
string arrToString(vector<int>& arr) {
    string result;
    for (int i = 0; i <= k; i++)
        result += (arr[i] + '0'); //결과 저장할 때 문자열로 바꿔서 저장
    return result;//결과 값 return
}

//과정에서의 답이 가능성 있는 답인지 체크하는 함수
bool promising(int idx) {
    if (op[idx] == '<' && arr[idx] > arr[idx + 1]) //부등호가 '<'인데 '>'관계일 때
        return false;//부등호 만족 못시킨경우
    if (op[idx] == '>' && arr[idx] < arr[idx + 1]) //부등호가 '>'인데 '<'관계일 때
        return false;//부등호 만족 못시킨경우
    return true;//부등호 만족 시킨경우
}

//최댓값 or 최솟값 구하는 백트래킹 함수 (num배열을 통해 구분)
void findValue(int cnt) {
    //수가 2개 이상이 배치됐다면, 주어진 부등호 만족하는지 검사, 만족하지 않으면 바로 리턴 (가지치기)
    if (cnt >= 2 && !promising(cnt - 2))//2개 이상 비교 숫자 배치됐고, 부등호 만족하지 않는 경우
        return;
    if (cnt == k + 1) { //부등호 만족하는 수를 찾음 (기저조건)
        is_find = true;//부등호 만족한다는 체크
        return;
    }
    for (int i = 0; i <= k; i++) { //num[i]: 최댓값이면 9 ~ (9-k), 최솟값이면 0 ~ k
        if (!check[num[i]]) {//숫자 사용 안된경우
            check[num[i]] = true;//그 수를 사용하기
            arr[cnt] = num[i];//저장된 수 저장
            findValue(cnt + 1);//다음 수 똑같이 진행
            if (is_find)//숫자 찾은 경우
                return;
            check[num[i]] = false;//선택한 숫자에 대한 체크 값 false로
            arr[cnt] = 0;//선택값 false 바껐으니 값 저장한 것도 없애기
        }
    }
}

/**
 * [백트래킹 풀이] (0ms)
 * 수를 중복없이 배치함 (N과 M(1)과 동일)
 * 수를 배치할 때마다 해당 수가 그 전 수와 부등호 관계를 만족하는지 확인, 만족하지 않으면 back (가지치기)
 */

int main() {
    string max_num, min_num; //정답

    //입력
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> op[i];//부등호 입력받기
    }

    //최댓값 연산
    for (int i = 0; i <= k; i++) //num배열에 값 미리 저장
        num[i] = 9 - i; //최댓값은 9부터 (9-k)까지 숫자로 이루어짐(가장 앞에수가 9인것이 최대라서)
    findValue(0);//최대값 찾기
    max_num = arrToString(arr);//수열 문자열로 바꾸기

    //초기화 !주의! 전역변수 사용 시 초기화 빼먹기 쉬우니 잘 체크하자
    is_find = false; //초기화 최대값에서 true로 바꾼거 최소 구할 때 바꿔야함
    check.assign(SIZE, false);//사이즈만큼 할당 초기화
    arr.assign(SIZE, 0);//사이즈만큼 할당 초기화

    //최솟값 연산
    for (int i = 0; i <= k; i++)
        num[i] = i; //최솟값은 0부터 k까지 숫자로 이루어짐
    findValue(0); //최소값 찾기
    min_num = arrToString(arr); //수열 문자열로 바꾸기

    //출력
    cout << max_num << '\n' << min_num;//출력하기

    return 0;
}