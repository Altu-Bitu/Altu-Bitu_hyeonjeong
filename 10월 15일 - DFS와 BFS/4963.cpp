#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<int>> isarr;
vector<vector<bool>> visited;
int main() {
	int w, h;
	
	queue<pair<bool, bool>> island;
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;

		isarr.assign(h, vector<int>(w, 0)); //섬에 대한 배열 초기화
		visited.assign(h, vector<bool>(w, 0)); //방문 여부 배열 초기화
		
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> isarr[i][j]; //입력받기

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {

			}
		}
	}
}