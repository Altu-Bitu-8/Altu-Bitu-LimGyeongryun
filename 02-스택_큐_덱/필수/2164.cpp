#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> deq;
    int n;
    cin >> n;

    // 1~n까지 덱에 푸시
    for (int i = 1; i <= n; i++) {
        deq.push_back(i);
    }

    while (deq.size() > 1) {
        deq.pop_front(); //앞 제거
        deq.push_back(deq.front()); //앞 숫자 뒤로 보내기 
        deq.pop_front(); //이동한 숫자 제거
    }

    cout << deq.front(); 

    return 0;
}
