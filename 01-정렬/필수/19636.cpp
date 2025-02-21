#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int W0, I0, T;
	int D, I, A;
	cin >> W0 >> I0 >> T;
	cin >> D >> I >> A;

	// 일일 기초 대사량의 변화를 고려하지 않았을 때
	int w1 = W0;
	int basic1 = I0;

	for (int i = 0; i < D; i++) {
		int weightDailyChange = I - (basic1 + A);
		w1 += weightDailyChange;

		// 체중 0 이하 시 사망 
		if (w1 <= 0) {
			cout << "Danger Diet" << endl;
			break;
		}
	}
	if (w1 > 0) {
		cout << w1 << " " << basic1 << endl;
	}

	// 일일 기초 대사량의 변화를 고려했을 때
	int w2 = W0;
	int basic2 = I0;
	bool dead = false;

	for (int i = 0; i < D; i++) {
		int weightDailyChange = I - (basic2 + A);
		w2 += weightDailyChange;

		// 체중 0 이하 시 사망
		if (w2 <= 0) {
			cout << "Danger Diet" << endl;
			dead = true;
			break;
		}

		// T초과시 기초대사량 변화
		if (abs(weightDailyChange) > T) {
			basic2 += floor(weightDailyChange / 2.0);
		}

		// 기초대사량 0 이하 시 사망
		if (basic2 <= 0) {
			cout << "Danger Diet" << endl;
			dead = true;
			break;
		}
	}
	if (!dead) {
		cout << w2 << " " << basic2 << " ";
		int reWeight = I0 - (basic2 + 0); //운동 안한다고 하니까 활동량 0
		if (reWeight > 0) {
			cout << "YOYO" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}