#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Person {
    int idx;  // 입력 순서
    int line; // 줄 번호
    int d;    // 근무 일수
    int h;    // 급한 정도
    Person(int i, int l, int dd, int hh) {
        idx = i;
        line = l;
        d = dd;
        h = hh;
    }
};

struct Compare {
    bool operator()(const Person& a, const Person& b) const {
        if (a.d != b.d) return a.d < b.d;         // 근무일수 높은 사람 우선
        if (a.h != b.h) return a.h < b.h;         // 급한 사람 우선
        return a.line > b.line;                   // 줄 번호 낮은 사람 우선
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<queue<Person>> lines(M);
    for (int i = 0; i < N; ++i) {
        int d, h;
        cin >> d >> h;
        int lineIdx = i % M; 
        lines[lineIdx].push(Person(i, lineIdx, d, h));
    }

    priority_queue<Person, vector<Person>, Compare> pq;

    // 각 줄의 맨 앞 사람을 우선순위 큐에 추가
    for (int i = 0; i < M; ++i) {
        if (!lines[i].empty()) {
            pq.push(lines[i].front());
            lines[i].pop();
        }
    }

    int count = 0;
    while (!pq.empty()) {
        Person cur = pq.top();
        pq.pop();

        if (cur.idx == K) break; // 데카 차례

        if (!lines[cur.line].empty()) {
            pq.push(lines[cur.line].front());
            lines[cur.line].pop();
        }

        count++;
    }

    cout << count << '\n';
    return 0;
}
