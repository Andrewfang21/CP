#include <bits/stdc++.h>
#define children nx
using namespace std;

const int n = 1e5 + 5, k = 30;

int N, Q;

struct Trie {
	struct Trie *children[k];
	int sizes;
};

struct Trie *getNode () {
	struct Trie *currPos = new Trie;

	currPos -> sizes = 0;
	for (int i = 0; i < k; i ++)
		currPos -> children[i] = NULL;

return currPos;
}

struct Trie *root = getNode();

int search (Trie *pos, string S) {

	Trie *currPos = pos;
	int res = 0;

	for (int i = 0; i < S.length(); i ++) {
		int idx = S[i] - 'a';

		if (currPos -> children[idx] == NULL)
			break;

		currPos = currPos -> children[idx];
		if (i == S.length() - 1)
			res += currPos -> sizes;
	}

return res;
}

void insert (Trie *pos, string S) {

	Trie *currPos = pos;
	for (int i = 0; i < S.length(); i ++) {
		int idx = S[i] - 'a';

		if (currPos -> children[idx] == NULL) {
			currPos -> children[idx] = getNode ();
		}

		currPos = currPos -> children[idx];

		// if (idx == 7)
		// 	cout << "tes " << currPos -> sizes << "\n";
	}
	currPos -> sizes ++;

//	cout << S << " " << currPos -> sizes << "\n";
}

int init (Trie *pos) {

	for (int i = 0; i < k; i ++) {
		if (pos -> children[i] != NULL) {
			pos -> sizes += init(pos -> children[i]);
		}
	}

return pos -> sizes;
}

void read () {
	cin >> N >> Q;
	for (int i = 1; i <= N; i ++) {
		string S;		cin >> S;
		insert(root, S);

//		print(root);
	}
}

void work () {
	
	root -> sizes = init(root);

//	cout << root -> children[2] -> children[0] -> children[19] -> children[0] -> sizes << "\n";
//	cout << root -> nx[2] -> nx[0] -> nx[19] -> nx[0] -> nx[18] -> nx[19] -> nx[17] -> nx[14] -> nx[15] -> nx[7] -> sizes << "\n";	


//	cout << root -> nx[2] -> nx[0] -> sizes << "\n";
	while (Q --) {
		string S;		cin >> S;

		int res = search(root, S);
		cout << res << "\n";
	}
}

int main () {
	ios_base::sync_with_stdio(false);

	read ();
	work ();

return 0;
}