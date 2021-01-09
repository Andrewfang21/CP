#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc --) {
		int n;
		cin >> n;

		int A[n + 5];
		for (int i = 0; i < n; i ++) {
			char c;
			cin >> c;
			A[i] = c - '0';
		}

		deque<int> v;
		int len = 1;
		int curr = A[0];
		for (int i = 1; i < n; i ++) {
			if (A[i] != A[i - 1]) {
				v.push_back(len);
				len = 1;
			} else len ++;
		}
		v.push_back(len);


		queue<int> not_one;
		for (int i = 0; i < v.size(); i ++) {
			if (v[i] != 1)	not_one.push(i);
		}

		int res = 0;
		int popped = 0;
		while (!v.empty()) {
			if (!not_one.empty()) {
				int pos = not_one.front() - popped;
				v[pos] --;
				if (v[pos] == 1)
					not_one.pop();
			} else {
				v.pop_front();
				popped ++;
			}

			if (!v.empty()) {
				if (!not_one.empty() && not_one.front() == popped) 
					not_one.pop(); 
				v.pop_front();
				popped ++;
			}

			res ++;
		}

		cout << res << "\n";
	}
}
