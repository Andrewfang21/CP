#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, q;
int A[N];

vector<int> cnt[N];

struct node {
	node *l, *r;
	int sum;
};
node* roots[N];

node *getNode(int value) {
	node *pos = new node();
	pos -> sum = value;
	pos -> l = pos -> r = NULL;

	return pos;
}

int getSum(node* &root) {return root ? root -> sum : 0;}

void add(node* &root) {
	if (root != NULL)
		root -> sum = getSum(root -> l) + getSum(root -> r);
}

node *insert(node* &root, int low, int high, int pos, int step = 0) {
	if (root == NULL) {
		root = getNode(0);
	}
	if (low == high) {
		node *curr = getNode(1);
		curr -> sum += getSum(root);

		return curr;
	}

	int mid = (low + high) / 2;
	node *curr = getNode(0);

	if (pos <= mid) {
		curr -> l = insert(root -> l, low, mid, pos, step + 1);
		curr -> r = root -> r;
	} else {
		curr -> l = root -> l;
		curr -> r = insert(root -> r, mid + 1, high, pos, step + 1);
	}

	add(curr);
	return curr;
}

int getKth(node* &root, int low, int high, int k) {
	if (low == high)
		return low;

	int mid = (low + high) / 2;
	if (getSum(root -> l) >= k)
		return getKth(root -> l, low, mid, k);

	return getKth(root -> r, mid + 1, high, k - getSum(root -> l));
}

void read() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i ++)
		scanf("%d", &A[i]);
}

void solve() {
	vector<int> V(A + 1, A + n + 1);
	
	sort(V.begin(), V.end());
	V.erase(unique(V.begin(), V.end()), V.end());
	int K = V.size();

	for (int i = 1; i <= n; i ++) {
        A[i] = (int)(lower_bound(V.begin(), V.end(), A[i]) - V.begin()) + 1;
    	cnt[A[i]].push_back(i);
	}
	
	roots[0] = getNode(0);
	for (int i = 1; i <= n; i ++)
		roots[i] = insert(roots[i - 1], 1, K, A[i]); 

	while (q --) {
		int k, range, tot;
		scanf("%d %d %d", &k, &range, &tot);

		int num = getKth(roots[range + 1], 1, K, k);
		if (cnt[num].size() < tot)
			printf("-1\n");
		else
			printf("%d\n", cnt[num][tot - 1] - 1);
	}
}

int main() {

	read();
	solve();

return 0;
}