#include<bits/stdc++.h>
using namespace std;

const int MAX_ALPHABET = 30;

int n, q;

struct trieNode {
	struct trieNode *child[MAX_ALPHABET];
	int sizes;

	trieNode() {
		this -> sizes = 0;

		for (int i = 0; i < MAX_ALPHABET; i ++)
			this -> child[i] = NULL;
	}

	int init(trieNode *currNode) {

		for (int i = 0; i < MAX_ALPHABET; i ++) {
			if (currNode -> child[i] != NULL)
				currNode -> sizes += init(currNode -> child[i]);
		}

		return currNode -> sizes;
	}

	void insert(string s) {
		trieNode *currNode = this;

		for (int i = 0; i < s.length(); i ++) {
			int idx = s[i] - 'a';

			if (currNode -> child[idx] == NULL)
				currNode -> child[idx] = new trieNode();

			currNode = currNode -> child[idx];
		}	

		currNode -> sizes ++;
	}

	int search(string s) {
		trieNode *currNode = this;

		int res = 0;
		for (int i = 0; i < s.length(); i ++) {
			int idx = s[i] - 'a';

			if (currNode -> child[idx] == NULL)
				break;

			currNode = currNode -> child[idx];
			if (i == s.length() - 1)
				res += currNode -> sizes;
		}

		return res;
	}
};

trieNode *node = new trieNode();

void read() {
	cin >> n >> q;
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;

		node -> insert(s);
	}
}

void solve() {
	node -> sizes = node -> init(node);

	while (q --) {
		string s;
		cin >> s;

		int res = node -> search(s);
		cout << res << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	read();
	solve();

return 0;
}
