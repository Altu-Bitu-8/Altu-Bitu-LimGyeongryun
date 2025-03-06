#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> deq;
    int n;
    cin >> n;

    // 1~n���� ���� Ǫ��
    for (int i = 1; i <= n; i++) {
        deq.push_back(i);
    }

    while (deq.size() > 1) {
        deq.pop_front(); //�� ����
        deq.push_back(deq.front()); //�� ���� �ڷ� ������ 
        deq.pop_front(); //�̵��� ���� ����
    }

    cout << deq.front(); 

    return 0;
}
