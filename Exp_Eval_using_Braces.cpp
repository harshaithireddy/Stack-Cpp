#include<bits/stdc++.h>
using namespace std;

bool isOper(char ch) {
    return (ch == '(' || ch == ')' || ch == '*' || ch == '+' || ch == '-');
}

int prec(char ch) {
    if (ch == '(' || ch == ')') return 0;
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*') return 2;
    return -1;
}

int Evaluate(char ch, int a, int b) {
    if (ch == '+') return (a + b);
    if (ch == '-') return (a - b);
    if (ch == '*') return (a * b);
    return 0;
}

int main() {
    string s = "24-3+4*(2+5)+1";

    stack<int> nums;
    stack<char> opers;

    for(int i = 0; i < s.size(); i++) {
        if(isdigit(s[i])) {
            int operand = 0;
            while(isdigit(s[i])) {
                operand = operand * 10 + (s[i] - '0');
                i++;
            }
            i--;
            nums.push(operand);
        }
        else if(isOper(s[i])) {
            if(s[i] == '(') {
                opers.push(s[i]);
            }
            else if(s[i] == ')') {
                while(!opers.empty() && opers.top() != '(') {
                    char op = opers.top();
                    opers.pop();
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    nums.push(Evaluate(op, a, b));
                }
                opers.pop(); 
            }
            else {
                while(!opers.empty() && prec(s[i]) <= prec(opers.top())) {
                    char op = opers.top();
                    opers.pop();
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    nums.push(Evaluate(op, a, b));
                }
                opers.push(s[i]);
            }
        }
    }

    while(!opers.empty()) {
        char op = opers.top();
        opers.pop();
        int b = nums.top();
        nums.pop();
        int a = nums.top();
        nums.pop();
        nums.push(Evaluate(op, a, b));
    }

    cout << nums.top() << endl;

    return 0;
}
