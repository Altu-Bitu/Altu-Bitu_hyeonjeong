#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    vector<int> coin;
    vector<int> dp;
    
    cin >> n >> k;
    coin.assign(n + 1, 0);
    dp.assign(k+1, 10001); dp[0] = 0; //초기화 
    for (int i = 1; i <= n; i++) {
        cin >> coin[i];
    }
   
    for (int i = 1; i <= n; i++) {
        for (int j = coin[i]; j <= k; j++) { //가치 합 k전까지 반복
            dp[j] = min(dp[j], dp[j - coin[i]] + 1); //동전 포함전, 포함후는 +1
        }
    }
    if (dp[k] == 10001)//실패조건 - 값 만들 수 없는경우
        cout << - 1<<'\n';
    cout << dp[k]<<'\n';
    return 0;

}