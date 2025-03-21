#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool isSimilar(string a, string b) {
    unordered_map<char, int> cnt;
    for (char c : a) cnt[c]++;
    for (char c : b) cnt[c]--;

    int moreA = 0, moreB = 0;
    for (auto p : cnt) {
        if (p.second > 0) moreA += p.second;
        else if (p.second < 0) moreB -= p.second;
    }

    return moreA <= 1 && moreB <= 1;
}

int countSimilar(string base, vector<string>& words) {
    int res = 0;
    for (string w : words) {
        if (isSimilar(base, w)) res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string base;
    cin >> base;

    vector<string> words(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> words[i];
    }

    cout << countSimilar(base, words) << '\n';
    return 0;
}

