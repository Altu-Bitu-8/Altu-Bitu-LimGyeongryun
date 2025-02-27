#include <iostream>
#include <set>

using namespace std;

// ���� �ٸ� ���ڿ� ���� ����
int countDifferentStrings(const string S) {
	set<string> M; //�ߺ� �����ؾ��ϹǷ� set�� ����

	//���ڿ� ���� ��ġ i, �� ��ġ j 
	for (size_t i = 0; i < S.size(); i++) { 
		for (size_t j = i; j < S.size(); j++) {
			M.insert(S.substr(i, j - i + 1)); 
		}
	}
	return M.size();
}

int main() {
	string S;
	cin >> S;
	cout << countDifferentStrings(S) << endl;
	
	return 0;
}