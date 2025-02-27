#include <iostream>
#include <set>

using namespace std;

// 서로 다른 문자열 개수 세기
int countDifferentStrings(const string S) {
	set<string> M; //중복 제거해야하므로 set에 저장

	//문자열 시작 위치 i, 끝 위치 j 
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