#include<bits/stdc++.h>
using namespace std;

bool isOper(char ch) {
	return (ch == '(' || ch == ')' || ch == '*' || ch == '+' || ch == '-');
}

int prec(char ch) {
	if(ch == '(' || ch == ')') return 3;
	if(ch == '*') return 2;
	return 1;
}

int Evaluate(char ch, int a, int b) {
	if(ch == '+') return (a + b);
	if(ch == '-') return (a - b);
	if(ch == '*') return (a * b);
}

int main() {
	string s = "2-3+4*(2+5)+1";
	stack<int> nums;
	stack<char> opers;

	for(int i = 0; i < s.size(); i++) {
		if(!isOper(s[i])) nums.push(s[i] - '0');
		else {
			if(opers.empty()) opers.push(s[i]);
			if(s[i] != '(' && s[i] != ')' && prec(s[i]) > prec(opers.top()))
				opers.push(s[i]);
			if(opers.top() == '(' && s[i] != ')') opers.push(s[i]);

		}
	}

}

