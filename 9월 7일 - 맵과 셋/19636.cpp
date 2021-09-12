#include<iostream>
#include<cmath>
using namespace std;

string sucDiet(int l, int q) {//다이어트 성공여부
	int n;
	string diet;
	n = l - (q + 0); //원래 섭취량 - (기초대사량 + 활동대사량)
	if (n > 0)
		diet = "YOYO";
	else
		diet = "NO";
	return diet;
}

int main(){
	int w0, l0, t, d, l, a;
	int w, q, day; //변화한체중, 변화한 기초대사량
	int n=0;
	string diet="";
	cin >> w0 >> l0 >> t; //전 체중, 에너지섭취량 및 일일기초대사량, 기초대사량역치
	cin >> d >> l >> a;//기간, 에너지 섭취량, 활동대사량
	w = w0; q = l0; day = d;

	while (day > 0) { //기초대사량 고려x
		n = l - (l0 + a);// (일일 에너지 섭취량 - 일일 에너지 소비량)
		w += n;
		day--;
	}
	if (w <= 0 || q <= 0) {
		diet = "Danger Diet";
		cout << diet << endl;
	}
	else {
		cout << w << ' ' << l0 << ' ' << diet << endl;
	}
	
	w = w0;
	day = d;
	while (day > 0) { //기초대사량 고려하는 경우
		n = l - (q + a);// (일일 에너지 섭취량 - 일일 에너지 소비량)

		if (abs(n) > t) {
			if (n < 0 && n % 2 != 0) //음수 계산 - 홀수인 음수
				q += (n / 2) - 1;
			else
				q += (n / 2);
		}
		w += n;
		day--;
	}

	diet = sucDiet(l0, q); //다이어트 성공,YOYO,danger
	if (w <= 0 || q <= 0) {
		diet = "Danger Diet";
		cout << diet;
	}
	else
		cout << w << ' ' << q <<' '<< diet<< endl; //기초대사량 고려

	
}