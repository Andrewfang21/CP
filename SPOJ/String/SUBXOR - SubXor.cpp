#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 5, MAX_BITS = 25;

int n, k;
int A[N], pref[N];

struct Trie {
	Trie *left, *right;
	ll sum, result;

	Trie() {
		this -> left = NULL;
		this -> right = NULL;
		this -> sum = 0;
		this -> result = 0;
	}

	int getSum(Trie *node) {
		return (node == NULL ? 0 : node -> sum);
	}

	void solve(int value, int target) {
		Trie *currNode = this;

		for (int i = MAX_BITS; i >= 0; i --) {
			if (currNode == NULL)
				break;

			int valBit = (value >> i) & 1;
			int targetBit = (target >> i) & 1;

			if (valBit == targetBit) {
				if (valBit == 1)
					this -> result += getSum(currNode -> right);

				currNode = currNode -> left;
			}
			else {
				if (valBit == 0)
					this -> result += getSum(currNode -> left);

				currNode = currNode -> right;
			}
		}
	}

	void update(int value) {
		Trie *currNode = this;

		for (int i = MAX_BITS; i >= 0; i --) {
			int bit = (value >> i) & 1;

			if (bit == 0) {
				if (currNode -> left == NULL)
					currNode -> left = new Trie();

				currNode = currNode -> left;
			}
			else {
				if (currNode -> right == NULL)
					currNode -> right = new Trie();

				currNode = currNode -> right;
			}

			currNode -> sum ++;
		}
	}

	ll getAns() {
		return this -> result;
	}
};

void solve() {
	scanf("%d %d", &n, &k);

	Trie *node = new Trie();
	node -> update(0);

	ll prefXor = 0;
	for (int i = 0; i < n; i ++) {
		int value;
		scanf("%d", &value);
	
		prefXor ^= value;
		
		node -> solve(prefXor, k);
		node -> update(prefXor);
	}

	printf("%lld\n", node -> getAns());
	free(node);
}

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc --) {
		solve();
	}

return 0;
}