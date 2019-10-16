#include<bits/stdc++.h>
using namespace std;

const int MAX_NUMBER = 10;

struct Trie {
	Trie *child[MAX_NUMBER];
	bool endOfWord, conflict;

	Trie() {
		this -> endOfWord = false;
		this -> conflict = false;

		for (int i = 0; i < MAX_NUMBER; i ++)
			this -> child[i] = NULL;
	}

	void insert(string s) {
		if (this -> conflict)
			return;

		Trie *currNode = this;

		for (int i = 0; i < s.length(); i ++) {
			int idx = s[i] - '0';

			if (currNode -> child[idx] == NULL)
				currNode -> child[idx] = new Trie();

			if (currNode -> endOfWord) {
				this -> conflict = true;
				break;
			}
			currNode = currNode -> child[idx];
		}

		currNode -> endOfWord = true;

		for (int i = 0; i < MAX_NUMBER; i ++) {
			if (currNode -> child[i]) {
				this -> conflict = true;
				break;
			}
		}
	}
};

Trie *node = new Trie();

void read() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		string s;
		cin >> s;

		node -> insert(s);
	}
}

void solve() {
	node -> conflict ? cout << "NO\n" : cout << "YES\n";

	node = new Trie();
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	while (tc --) {
		read();
		solve();
	}

return 0;
}