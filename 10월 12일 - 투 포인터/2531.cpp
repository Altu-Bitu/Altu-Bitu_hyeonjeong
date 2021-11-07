//추가제출

#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(vector<int>& belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0); //먹은 초밥 저장하기위한 배열

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;//하나 먹은거 표시
    sushi[c]++; //쿠폰으로 먹은거 먼저 고려

    //윈도우 초기화
    for (int i = 0; i < k; i++) {//연속해서 먹는 수만큼 진행
        sushi[belt[i]]++;//회전 초밥 접시에 있는거 하나 먹었을때 그 배열의 첨자로 가서 먹은거 표시
        if (sushi[belt[i]] == 1) //먹은표시한경우
            section_sushi++;  //스시 개수 추가
    }

    int ans = section_sushi;  //연속해서 먹는수 체크위해
    int left = 0, right = k - 1; //투포인터사용
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        sushi[belt[left]]--; //현재 먹은거 위치에서 왼쪽으로 늘리기
        if (!sushi[belt[left]]) //종료조건이면
            section_sushi--; //스시 수 줄이기

        //윈도우의 양 끝 이동
        left = (left + 1) % n;//원이라서 %이용하여 한칸 이동
        right = (right + 1) % n; //원이라서 %이용하여 한칸 이동

        sushi[belt[right]]++; ///오른쪽으로 늘리기
        if (sushi[belt[right]] == 1) //표시한 스시이면
            section_sushi++; //스시 개수 추가

        ans = max(ans, section_sushi); //최대 스시 개수 구하기
    } while (left); //종료조건 left=0이 아니면 게속 진행
    return ans;//빠져나오면 반환
}

int main() {
    int n, d, k, c; //접시의 수, 초밥의 가짓수, 연속해서 먹는접시의 수,쿠폰번호

    //입력
    cin >> n >> d >> k >> c;//입력받기
    vector<int> belt(n, 0); //회전 초밥 접시 n개 초기화
    for (int i = 0; i < n; i++)
        cin >> belt[i]; //d 까지의 초밥 고려해서 입력받기

    //연산 & 출력
    cout << chooseSushi(belt, n, d, k, c);//회전 초밥 접시, 접시 수 가짓수, 연속해서 먹는수, 쿠폰번호 전달해서 최대값 구하기
}