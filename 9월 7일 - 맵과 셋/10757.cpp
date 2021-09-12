#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sum; 

void sumFunc(int b_size, int s_size, string big, string small) {//더해주는 함수(큰 자릿수, 작은 자릿수, 큰 수 ,작은수)
	int i, total = 0, carry = 0;
	for (i = 0; i < s_size; i++) { //자릿수 작은 것 기준으로 더하기
		total = (big[b_size - (i + 1)] - '0') + (small[s_size - (i + 1)] - '0'); //반올림 수 있는 것까지 더해주기
		if (total >= 10) {//반올림 된다면
			sum.push_back(total - 10 + carry); //sum[0]이 일의 자리수
			carry = 1; // 그 다음 자리에 1올리기
		}
		else {
			sum.push_back(total + carry);
			carry = 0;

		}
	}

	if (b_size - i != 0) { // 자릿수 큰거 더해주기
		for (; i < b_size; i++) {// 혼자 더하기
			if ((big[b_size - (i + 1)] - '0') + carry >= 10) { //캐리랑 더한 값이 10보다 크면
				sum.push_back((big[b_size - (i + 1)] - '0') + carry - 10);
				carry = 1;
			}
			else {
				sum.push_back((big[b_size - (i + 1)] - '0') + carry);
				carry = 0;
			}
		}
	}

	if (b_size - i == 0 && carry == 1) { //마지막 연산에서 carry 발생한 경우
		sum.push_back(1);
	}
}

void sizeCompare(int asize, int bsize, string a, string b) {
	if (asize >= bsize) //a자릿수 크기가 b자릿수보다 크거나 같은경우
		sumFunc(asize, bsize, a, b);
	else 
		sumFunc(bsize, asize, b, a);
}
int main() {
	string a, b;
	int a_size, b_size;
	//입력
	cin >> a >> b;
	a_size = a.length();
	b_size = b.length();

	//크기비교
	sizeCompare(a_size, b_size,a,b);

	//출력
	for (int i = sum.size()-1; i >=0; i--) {
		cout << sum[i];
	}
	
	return 0;
}