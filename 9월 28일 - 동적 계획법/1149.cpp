#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dp[1001][3] = { 0, };
    int rgb[3];
    int n;

    cin >> n;//집의 수
    for (int i = 1; i <= n; i++) {//i-1더해야하니까 i=1부터 시작
        cin >> rgb[0] >> rgb[1] >> rgb[2]; //색상에 대한 비용(r,g,b)
        //bottom-up방식
        dp[i][0] = rgb[0] + min(dp[i - 1][1], dp[i - 1][2]);//i번째가 r인경우
        dp[i][1] = rgb[1] + min(dp[i - 1][0], dp[i - 1][2]);//g인경우
        dp[i][2] = rgb[2] + min(dp[i - 1][0], dp[i - 1][1]);//b인 경우
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
    return 0;
}