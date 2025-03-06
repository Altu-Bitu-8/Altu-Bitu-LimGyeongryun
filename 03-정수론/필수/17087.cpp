#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//거리 계산
vector<int> absDistance(const vector<int>& arr, int s) {
	vector<int> distance(arr.size());
	for (int i = 0; i < arr.size(); i++) {
		distance[i] = abs(s - arr[i]);
	}
	return distance;
}

// 최대공약수 계산
int findGCD(const vector<int>& distance) {
	int answer = distance[0];
	for (int i = 1; i < distance.size(); i++) {
		answer = __gcd(answer, distance[i]);
	}
	return answer;
}


int main() {
	int n, s;
	cin >> n >> s;

	vector<int> arr(n);
	for (int i = 0; i < n;i++) {
		cin >> arr[i];
	}

	vector<int> distance = absDistance(arr, s);

	int result = findGCD(distance);

	cout << result << "\n";

	return 0;
}