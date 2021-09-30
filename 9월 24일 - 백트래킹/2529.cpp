#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<char> sign;
vector<bool> check(10,0);
vector<string> sizecompa; 
void backtracking(int signsize) {
	string max, min;
	string num=" ";
	if (signsize > sign.size() ) {//숫자 다 채운 경우(k+1만큼)

	}

	for (int i = 0; i < 10; i++) {
		if (check[i] == 0) {
			if (num == " ") {
				num += i;
				continue;
			}
				
			if(sign[i]=='<')

		}
	}
	
}

int main() {
	int k;
	int minnum, maxnum;
	cin >> k;
	sign.assign(k, ' ');
	
	for (int i = 0; i < k; i++) 
		cin >> sign[i]; //부등호 입력

	
	backtracking(0);
	

}