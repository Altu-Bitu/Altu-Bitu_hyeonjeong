#include<iostream>
#include<cctype>
using namespace std;

int sizeFind(int r,int b,int sum) {
	for (int i = 3; i <= sum / 2; i++) {
		if ((sum/i)*i == sum) {// w * l = 타일의 전체 개수
			int j = sum / i;
			int num = i * 2 + j * 2 - 4;//테두리 타일 개수
			if (num == r) {//테두리 타일 개수와 빨간색 타일 개수 같으면
				return max(i, j);
			}
		}
	}
	return 0;
}

int main() {
	int r, b; //빨간색 타일의 수, 갈색 타일의 수
	int length;
	cin >> r >> b;
	int sum = r + b;

	length = sizeFind(r, b, sum); //높이 너비 길이 구하기

	cout << length << ' ' << sum / length;
	return 0;

}