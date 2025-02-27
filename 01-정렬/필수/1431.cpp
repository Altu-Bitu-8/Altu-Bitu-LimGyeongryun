#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �ø����ȣ�� ��� ���� �� ��� �Լ�
int sumNumber(const string S) {
	int sum = 0;
	for (int i = 0; i < S.size(); i++) {
		if (isdigit(S[i])) {
			sum += S[i] - '0';
		}
	}
	return sum;
}

// �ø����ȣ �� �Լ� 
bool compareNumber(const string A, const string B) {

	// 1�ܰ� - ���� �� (ª�� �� ����)
	if (A.size() != B.size()) {
		return A.size() < B.size();
	}

	// 2�ܰ� - ��� ���� �� �� (���� �� ����)
	int ASum = sumNumber(A);
	int BSum = sumNumber(B);

	if (ASum != BSum) {
		return ASum < BSum;
	}

	// 3�ܰ� - ������ �� 
	return A < B; 
}

int main() {
	int N; //�ø��� ��ȣ ����
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