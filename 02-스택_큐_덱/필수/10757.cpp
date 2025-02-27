#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> addNumber(string a, string b) {
	deque<int> result;
	int carry = 0; //¿Ã¸²¼ö 

	int i = a.size() - 1;
	int j = b.size() - 1;

	while (i >= 0 || j >= 0 || carry) {
		int num1 = 0, num2 = 0;

		if (i >= 0) {
			num1 = a[i] - '0';
			i--;
		}

		if (j >= 0) {
			num2 = b[j] - '0';
			j--;
		}

		int sum = num1 + num2 + carry;
		carry = sum / 10;
		result.push_front(sum % 10);
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	deque<int> sum = addNumber(a, b);

	for (int i = 0; i < sum.size(); i++) {
		cout << sum[i];
	}

	return 0;
}