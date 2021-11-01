#include<iostream>
#include<vector>
using namespace std;

int arr[100001] = { 0, }; //중복되는 원소 체크
vector<int> seqnum;

int twoPoint(int n, int k) {
	int left = 0, right = 0;
	int maxlen = 0,len =0;

	while(left<=right && right<n){
		while (right < n && left<=right) {//구간 멀어지기
			arr[seqnum[right]]++; //중복체크
			if (arr[seqnum[right]] > k)// k 보다 커지는 경우 break
				break;
			right++; len++;
			
		}
		maxlen = max(len, maxlen); //최대 수열 길이

		while (right<n && left < right) { //k 넘은 경우 구간 가까워지기
			
			if (arr[seqnum[left]] > k) {// k보다 큰 경우를 만났을 때
				arr[seqnum[left]]--;
				left++; right++;
				break;
			}
			arr[seqnum[left]]--;
			left++; len--;
		}

	}
	return maxlen;
}

int main() {
	int n, k;
	cin >> n >> k;
	seqnum.assign(n, 0);

	for (int i = 0; i < n; i++)
		cin >> seqnum[i];

	cout<<twoPoint(n, k);

	return 0;
}