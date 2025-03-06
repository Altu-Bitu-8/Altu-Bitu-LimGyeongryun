#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int n, k;
string arr;
int currentIndex = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    arr.assign(n, '?'); //배열 ?로 초기화

    for (int i = 0; i < k; i++) {
        int step;
        char ch;
        cin >> step >> ch;

        // 원형 인덱스 계산
        int nextIndex = ((currentIndex - step) % n + n) % n;

        // 같은 위치에 다른 문자가 오면 "!" 출력 후 종료
        if (arr[nextIndex] != '?' && arr[nextIndex] != ch) {
            cout << "!\n";
            return 0;
        }

        arr[nextIndex] = ch;
        currentIndex = nextIndex;
    }

    // 중복 문자 검사 
    bitset<26> seen;
    for (char c : arr) {
        if (c == '?') continue;
        if (seen[c - 'A']) {
            cout << "!\n";
            return 0;
        }
        seen.set(c - 'A');
    }

    // 현재 위치에서 시계 방향으로 출력
    for (int i = 0; i < n; i++) {
        cout << arr[(currentIndex + i) % n];
    }
    cout << "\n";

    return 0;
}
