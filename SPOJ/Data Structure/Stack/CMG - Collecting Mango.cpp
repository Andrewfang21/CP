#include<bits/stdc++.h>
using namespace std;

void solve(int tc) {
	printf("Case %d:\n", tc);
	stack<int> st;

	int Q;
	cin >> Q;

	while (Q --) {
		char query;
		int x;

		scanf("\n%c", &query);
		if (query == 'A') {
			scanf("%d", &x);
			if (st.empty())
				st.push(x);
			else {
				x > st.top() ? st.push(x) : 
							   st.push(st.top());
			}
		}	
		else 
		if (query == 'R') {
			if (!st.empty())
				st.pop();
		}
		else {
			st.empty() ? printf("Empty\n") : 
						 printf("%d\n", st.top());
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);

	for (int i = 1; i <= tc; i ++) {
		solve(i);
	}

return 0;
}