//추가제출
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int>& num, int left, int right, int idx) { //배열을 주소로 전달 받았으므로 변경된 부분 그대로 전달
    while (left < right) {//빠져나올 조건 항상 오른쪽 인덱스가 큼
        if (left == idx) { //left가 현재 수 위치와 같은 경우
            left++;// 왼쪽 인덱스를 옮겨서 구간 줄이기
            continue;
        }
        if (right == idx) { //right가 현재 수 위치와 같은 경우
            right--; // 오른쪽 인덱스를 줄여서 구간 줄이기
            continue;
        }

        if (num[left] + num[right] == num[idx])//만약 숫자들 더해서 현재 인덱스에 있는 값과 같은 값을 찾는다면
            return true;//1반환하기

        if (num[left] + num[right] > num[idx]) //만드려는 수보다 크다면
            right--; //오른쪽이 가장 크므로 숫자를 줄여주기
        else
            left++;// 만들려는 수보다 작으면 왼쪽을 크게 만들어서 더한값이 현재 구하려는 값과 같도록 탐색한다.
    }
    return false;//왼쪽이 커서 빠져나왔는데도 값이 만족 하지 못한다면 0반환하기
}



int main() {
    int n, ans = 0; //수의 개수, 좋은 수 개수

    //입력
    cin >> n; //수의 개수 입력
    vector<int> num(n, 0); //전체 수의 개수만큼 배열 초기화
    for (int i = 0; i < n; i++)
        cin >> num[i];// 숫자들 입력받기

    //연산
    sort(num.begin(), num.end()); //좋은수 찾기 위해 오름차순 정렬하기
    for (int i = 0; i < n; i++) {
        if (isGood(num, 0, n - 1, i))//좋은 수 만족하는지 여부를 알기 위해 함수 호출(전체수, 왼쪽, 오른쪽, 인덱스)
            ans++; //좋은 수이면 ++
    }

    //출력
    cout << ans << '\n'; //좋은 수 개수 출력한다.

    return 0;
}