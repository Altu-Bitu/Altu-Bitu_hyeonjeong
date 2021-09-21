#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string cppTojava(string str) {
	string comp = ""; //완성된 값

	if (str[0] == '_' || str[str.size() - 1] == '_') //1. 처음,맨뒤에 '_'인 경우
		return "Error!";

	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) //2. 대문자인경우
			return "Error!";

		if (str[i] == '_') {
			if (str[i + 1] == '_') //3. 연속 '__'인 경우
				return "Error!";
			comp += toupper(str[++i]); // 다음 글자 대문자로 바꿔서 저장
		}
		else
			comp += str[i];
	}
	return comp;
}

string javaTocpp(string str) {
	string comp = ""; //완성된 값


	if (!islower(str[0])) //1. 첫글자 대문자면 오류
		return "Error!";

	for (int i = 0; i < str.size(); i++) {
		if (!islower(str[i]) && !isupper(str[i]))
			return "Error!"; // 2. 알파벳 아닌 경우 에러

		if (isupper(str[i])) { //대문자인 경우 '_',소문자로 변경
			comp += '_';
			comp += tolower(str[i]);
		}
		else
			comp += str[i];
	}
	return comp;
}


string isType(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) {// 대문자인 경우 java
			return javaTocpp(str);
		}
		else if (str[i] == '_') {// '_' 있는 경우 cpp

			return cppTojava(str);
		}
	}

	return str;// 대문자, '_' 모두 없는 경우

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;

	cin >> str;//입력

	cout << isType(str); //c++인지 java인지 둘다 아닌지 판별


	return 0;
}