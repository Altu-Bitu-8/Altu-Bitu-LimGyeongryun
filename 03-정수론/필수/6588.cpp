#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const int n = 1000000;
bool isPrime[n];
vector<int> primeList;

//소수배열 만들기
void findPrime() {
	fill(isPrime, isPrime + n, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i < n; i++) {
		if (isPrime[i]) { 
			for (int j = i * i; j < n; j += i) { 
				isPrime[j] = false;
			}
		}
	}
	primeList.push_back(2);
	for (int i = 3; i < n; i += 2) {
		if (isPrime[i]) {
			primeList.push_back(i);
		}
	}
}

string goldbach(int a) {
	if (a < 4 || a % 2 != 0) {
		return "Goldbach's conjecture is wrong.\n";
	}

	for (int prime : primeList){
		if (prime > a / 2) break;
		if (isPrime[a - prime]) {
			ostringstream result;
			result << a << " = " << prime << " + " << (a - prime) << "\n";
			return result.str();
		}

	}	
	return "Goldbach's conjecture is wrong.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	
	findPrime();

	while (cin >> num && num != 0) {
		cout << goldbach(num);
	}

	return 0;
}