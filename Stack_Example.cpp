// Family members with same age will kill each other when they are side-by-side 

#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> V = {14, 13, 13, 14, 12, 11, 11, 12, 1, 5, 5, 1, 6, 7, 8};
	stack<int> st;

	for(int i = 0; i < V.size(); i++) {
		if(st.empty()) st.push(V[i]);

		else if(st.top() != V[i]) {
			st.push(V[i]);
		}
		else if(st.top() == V[i]) {
			if(!st.empty())
				st.pop();
		}
	}
	if(st.empty()) cout << "0";
	else cout << st.size();
}
