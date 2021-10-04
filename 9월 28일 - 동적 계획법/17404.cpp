#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp[1001][3] = { 0, };//집 비용 계산
    int rgb[1001][3] = { 0, };//가격 입력 받음
    int n;
    int result = 100001;
    cin >> n;//집의 수
    for (int i = 1; i <= n; i++) //i-1더해야하니까 i=1부터 시작
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2]; //색상에 대한 비용(r,g,b)

    for (int j = 0; j < 3; j++) {

        for (int i = 0; i < 3; i++) {//첫번쨰 색상 선택
            if (i == j)
                dp[1][i] = rgb[1][i];
            else
                dp[1][i] = 1000002;
        }

        for (int i = 2; i <= n; i++) {
            //bottom-up방식
            dp[i][0] = rgb[i][0] + min(dp[i - 1][1], dp[i - 1][2]);//i번째가 r인경우
            dp[i][1] = rgb[i][1] + min(dp[i - 1][0], dp[i - 1][2]);//g인경우
            dp[i][2] = rgb[i][2] + min(dp[i - 1][0], dp[i - 1][1]);//b인 경우

        }
        for (int k = 0; k < 3; k++) {
            if (j == k) continue; //처음에 기억한 숫자랑 같으면 패스
            result = min(result, dp[n][k]);
        }
    }

    cout << result;
    return 0;
}