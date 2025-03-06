#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {
        string str;
        getline(cin, str);

        if (str == ".") break; // 종료 조건

        stack<char> charStack;
        bool isMatched = true;

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];

            if (ch == '(' || ch == '[') {
                charStack.push(ch);
            }
            else if (ch == ')') {
                if (charStack.empty() || charStack.top() != '(') {
                    isMatched = false;
                    break;
                }
                charStack.pop();
            }
            else if (ch == ']') {
                if (charStack.empty() || charStack.top() != '[') {
                    isMatched = false;
                    break;
                }
                charStack.pop();
            }
        }

        if (isMatched && charStack.empty()) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
