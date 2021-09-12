//생태학

#include<iostream>
#include<map>
#include<string>
#include<cmath>

using namespace std;

int main() {
	string n;
	int num = 0; //전체 개수 카운트
	map<string, int> tree;

	while (true) {
		getline(cin, n);
		if (n == "")
			break;
		num++;
		if (tree.find(n) == tree.end()) {//tree이름 처음 나온경우
			tree[n] = 1;
		}
		else
			tree[n]++;
	}

	cout << fixed; //소수점을 고정시켜 표현
	cout.precision(4);// 소수점 4자리까지 표현(반올림)

	float result;
	for (auto iter : tree) {
		result = ((float)iter.second / (float)num *100); //백분율
		cout << iter.first << ' ' << result << endl;
	}
	return 0;
}
