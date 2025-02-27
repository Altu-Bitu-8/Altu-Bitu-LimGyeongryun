#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시리얼번호의 모든 숫자 합 계산 함수
int sumNumber(const string S) {
	int sum = 0;
	for (int i = 0; i < S.size(); i++) {
		if (isdigit(S[i])) {
			sum += S[i] - '0';
		}
	}
	return sum;
}

// 시리얼번호 비교 함수 
bool compareNumber(const string A, const string B) {

	// 1단계 - 길이 비교 (짧은 게 먼저)
	if (A.size() != B.size()) {
		return A.size() < B.size();
	}

	// 2단계 - 모든 숫자 합 비교 (작은 게 먼저)
	int ASum = sumNumber(A);
	int BSum = sumNumber(B);

	if (ASum != BSum) {
		return ASum < BSum;
	}

	// 3단계 - 사전식 비교 
	return A < B; 
}

int main() {
	int N; //시리얼 번호 개수
	cin >> N;
	vector<string> num(N);
	
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end(), compareNumber);

	for (int i = 0; i < num.size(); i++) {
		cout << num[i] << endl;
	}

	return 0;
}