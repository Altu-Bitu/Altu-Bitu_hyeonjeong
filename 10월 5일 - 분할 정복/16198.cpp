#include <iostream>
#include <vector>

using namespace std;

vector<int> w; //에너지 저장된 배열
int ans;// 에너지최대 구하기

void backtracking(int sum) {//에너지 합 구하는 함수
    if (w.size() == 2) { //에너지 구슬이 2개 -> 더 이상 고를 수 없음
        ans = max(ans, sum);//현재에너지 합과 원래 저장된 합중에 큰 거 선택
        return;
    }
    for (int i = 1; i < w.size() - 1; i++) { //처음과 마지막 선택 불가이므로
        int temp_w = w[i];//다시 돌려놓기 위해 임시저장
        int sum_w = w[i - 1] * w[i + 1];//에너지 구해서 더하기
        w.erase(w.begin() + i);//i번째에 있는 에너지 삭제
        backtracking(sum + sum_w); //에너지 합 구하기
        w.insert(w.begin() + i, temp_w); //다시 다음꺼할때는 값 복구해서 에너지합 구하도록함
    }
}

/**
 * 가능한 모든 경우를 구해서 계산하자
 * 이때, 사용한 에너지는 따로 저장해 둔 후에 배열에서 지우고, 다시 돌아왔을 때 저장한 값을 배열에 넣는다.
 */
int main() {
    int n;

    //입력
    cin >> n;
    w.assign(n, 0);//에너지 배열 크기 선언
    for (int i = 0; i < n; i++)
        cin >> w[i]; //에너지 입력

    //연산
    backtracking(0);

    //출력
    cout << ans << '\n';

    return 0;
}