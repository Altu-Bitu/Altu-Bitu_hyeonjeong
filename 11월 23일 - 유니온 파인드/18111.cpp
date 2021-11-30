#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

int mineLand(int n, int m, int b, int height, vector<vector<int>>& land) { //땅고르기작업
    int tot_time = 0; //현재 진행 시간 저장
    for (int i = 0; i < n; i++) {//줄의 개수만큼 
        for (int j = 0; j < m; j++) {//땅높이만큼
            if (land[i][j] > height) { //블록 제거하는 연산
                b += (land[i][j] - height); //높이 저장
                tot_time += 2 * (land[i][j] - height); //전체 시간 늘리기
            }
            else if (land[i][j] < height) { //블록 쌓기
                b -= (height - land[i][j]); //블록 하나 제거
                tot_time += (height - land[i][j]); //블록개수만큼 시간 추가
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1; //불가능한숫자 반환
    return tot_time; //최소 시간 반환
}

/**
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 * !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
 */
int main() {
    int n, m, b, min_height = 256, max_height = 0; //행, 열 , 최소높이, 최대높이저장

    //입력
    cin >> n >> m >> b; //줄, 땅의 높이 저장
    vector<vector<int>> land(n, vector<int>(m, 0)); //입력받는 크기만큼 땅의 크기 저장
    for (int i = 0; i < n; i++) {//줄의 크기
        for (int j = 0; j < m; j++) { //땅의 높이
            cin >> land[i][j]; //현재 땅 입력받기
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0; //최소 시간, 높이저장
    for (int i = min_height; i <= max_height; i++) { //최대 높이 만큼 진행
        int t = mineLand(n, m, b, i, land); //땅의최소 시간 저장
        if (t <= min_time) { //가장 빨리 작업이 끝나는 높이
            min_time = t; //최소시간
            height = i; //높이저장
        }
    }

    //출력
    cout << min_time << ' ' << height; //땅고르는데 걸린시간, 땅의 높이 출력
}