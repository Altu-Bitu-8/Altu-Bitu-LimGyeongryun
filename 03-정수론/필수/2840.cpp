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
    arr.assign(n, '?'); //�迭 ?�� �ʱ�ȭ

    for (int i = 0; i < k; i++) {
        int step;
        char ch;
        cin >> step >> ch;

        // ���� �ε��� ���
        int nextIndex = ((currentIndex - step) % n + n) % n;

        // ���� ��ġ�� �ٸ� ���ڰ� ���� "!" ��� �� ����
        if (arr[nextIndex] != '?' && arr[nextIndex] != ch) {
            cout << "!\n";
            return 0;
        }

        arr[nextIndex] = ch;
        currentIndex = nextIndex;
    }

    // �ߺ� ���� �˻� 
    bitset<26> seen;
    for (char c : arr) {
        if (c == '?') continue;
        if (seen[c - 'A']) {
            cout << "!\n";
            return 0;
        }
        seen.set(c - 'A');
    }

    // ���� ��ġ���� �ð� �������� ���
    for (int i = 0; i < n; i++) {
        cout << arr[(currentIndex + i) % n];
    }
    cout << "\n";

    return 0;
}
