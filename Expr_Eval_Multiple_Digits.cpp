#include<bits/stdc++.h>
using namespace std;

int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else {
        return 2;
    }
}

int evaluate(int n1, int n2, char op) {
    if (op == '*') return n1 * n2;
    if (op == '+') return n1 + n2;
    if (op == '-') return n1 - n2;
    if (op == '/') return int(n1 / n2);
    return 0;
}

int main() {
    string s;
    cin >> s;
    stack<int> Numbers;
    stack<char> Operators;

    for (int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') continue;
        if (s[i] <= '9' && s[i] >= '0') {
            int n = 0;
            while (s[i] <= '9' && s[i] >= '0') {
                n = n * 10 + int(s[i] - '0');
                i = i + 1;
            }
            i = i - 1;
            Numbers.push(n);
        } else {
            if (Operators.empty()) {
                Operators.push(s[i]);
            } else {
                if (priority(s[i]) > priority(Operators.top())) {
                    Operators.push(s[i]);
                } else {
                    while (!Operators.empty() && priority(s[i]) <= priority(Operators.top())) {
                        int n1 = Numbers.top();
                        Numbers.pop();
                        int n2 = Numbers.top();
                        Numbers.pop();
                        int ans = evaluate(n2, n1, Operators.top());
                        Operators.pop();
                        Numbers.push(ans);
                    }
                    Operators.push(s[i]);
                }
            }
        }
    }

    while (!Operators.empty()) {
        int n1 = Numbers.top();
        Numbers.pop();
        int n2 = Numbers.top();
        Numbers.pop();
        int ans = evaluate(n2, n1, Operators.top());
        Operators.pop();
        Numbers.push(ans);
    }

    cout << Numbers.top() << endl;
    return 0;
}
