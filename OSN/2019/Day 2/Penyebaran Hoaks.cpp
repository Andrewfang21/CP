#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

const int n = 2e5 + 5;

int N, S, Q;
int parent[n], sizes[n], height[n];

typedef pair<pair<int, int>, int> ii;
vector<ii> V;

void read () {
	cin >> N >> S >> Q;
	for (int i = 1; i <= N; i ++) {
		int T;		cin >> T;
		for (int j = 1; j <= T; j ++) {
			int A, B;
			cin >> A >> B;

			V.pb(mp(mp(A, 0), i));
			V.pb(mp(mp(B, 1), i));
		}

		parent[i] = i, sizes[i] = 1, height[i] = 1;
	}
}

int findSet (int X) {
	if (parent[X] == X)
		return X;
	else {
		int temp = findSet(parent[X]);
		parent[X] = temp;

		return temp;
	}
}

int getSize (int X) {return sizes[findSet(X)];}

void mergeSet (int a, int b) {
	int x, y;
	x = findSet(a);		y = findSet(b);

	if (x == y)	return;

	if (height[x] >= height[y]) {
		parent[y] = x;
		sizes[x] += sizes[y];		sizes[y] = 0;
	} else {
		parent[x] = y;
		sizes[y] += sizes[x];		sizes[x] = 0;
	}

	if (height[x] == height[y])		height[x] ++;
}

void solve () {
	sort(V.begin(), V.end());

	set<int> S;
	int prevUser, currUser, status;
	for (int i = 0; i < V.size(); i ++) {
		if (i == 0)
			S.insert(V[i].second);
		else {
			currUser = V[i].second;
			status = V[i].first.second;

			if (status == 0) {
				if (!S.empty()) {
					prevUser = *S.begin();
					mergeSet(prevUser, currUser);
				}
				S.insert(currUser);
			} else {
				S.erase(currUser);
			}
		}
	}

	while (Q --) {
		int query;		cin >> query;
		cout << getSize(query) << "\n";
	}
}


int main () {
	ios_base::sync_with_stdio(false);
	
	read ();
	solve ();

return 0;
}
