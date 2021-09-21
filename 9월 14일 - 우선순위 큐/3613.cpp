#include<iostream>
#include<string>
#include<cctype>

using namespace std;

string cppTojava(string str) {
	string comp = ""; //�ϼ��� ��

	if (str[0] == '_' || str[str.size() - 1] == '_') //1. ó��,�ǵڿ� '_'�� ���
		return "Error!";

	for (int i = 0; i < str.size(); i++) {
		if (isupper(str[i])) //2. �빮���ΰ��
			return "Error!";

		if (str[i] == '_') {
			if (str[i + 1] == '_') //3. ���� '__'�� ���
				return "Error!";
			comp += toupper(str[++i]); // ���� ���� �빮�ڷ� �ٲ㼭 ����
		}
		else
			comp += str[i];
	}
	return comp;
}

string javaTocpp(string str) {
	string comp = ""; //�ϼ��� ��


	if (!islower(str[0])) //1. ù���� �빮�ڸ� ����
		return "Error!";

	for (int i = 0; i < str.size(); i++) {
		if (!islower(str[i]) && !isupper(str[i]))
			return "Error!"; // 2. ���ĺ� �ƴ� ��� ����

		if (isupper(str[i])) { //�빮���� ��� '_',�ҹ��ڷ� ����
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
		if (isupper(str[i])) {// �빮���� ��� java
			return javaTocpp(str);
		}
		else if (str[i] == '_') {// '_' �ִ� ��� cpp

			return cppTojava(str);
		}
	}

	return str;// �빮��, '_' ��� ���� ���

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;

	cin >> str;//�Է�

	cout << isType(str); //c++���� java���� �Ѵ� �ƴ��� �Ǻ�


	return 0;
}