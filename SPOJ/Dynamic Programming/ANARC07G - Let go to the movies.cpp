#include<bits/stdc++.h>
#pragma GCC Optimize("O3")
#define MP make_pair
#define F first
#define S second
using namespace std;

const int N = 1e5 + 5;
typedef pair<int, int> PAIR;

int n, SPrice, FPrice;
PAIR dp[N][2];

bool isChild[N];

vector<int> adj[N];
map<string, int> rec;

int getID(string name) {
	if (rec[name] == 0)
		rec[name] = ++ n;

return rec[name];
}

int getCost(PAIR t) {
	return t.F * FPrice + t.S * SPrice;
}

int getTickets(PAIR t) {
	return t.F + t.S;
}

void inc(PAIR &target, PAIR adder) {
	target.F += adder.F;
	target.S += adder.S;
}

void reset() {
	n = 0;
	rec.clear();
	for (int i = 0; i < N; i ++)
		adj[i].clear();

	memset(isChild, false, sizeof(isChild));
	memset(dp, -1, sizeof(dp));
}

PAIR solve(int pos, int isActive) {
	if (adj[pos].size() == 0)
		return isActive == 1 ? MP(0, 0) : MP(0, 1);

	PAIR &ret = dp[pos][isActive];
	if (ret.first != -1 && ret.second != -1)
		return ret;

	ret = MP(0, 0);

	PAIR fTicket = MP(1, 0);
	for (int next : adj[pos]) 
		inc(fTicket, solve(next, 1));

	PAIR sTicket = MP(0, 1 - isActive);
	for (int next : adj[pos])
		inc(sTicket, solve(next, 0));

	if (getCost(fTicket) == getCost(sTicket)) {
		ret = getTickets(fTicket) < getTickets(sTicket) ? fTicket : sTicket;
	} 
	else 
		ret = getCost(fTicket) < getCost(sTicket) ? fTicket : sTicket;

return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	int tc = 0;
	while (cin >> SPrice >> FPrice) {
		if (SPrice == 0 && FPrice == 0)
			break;
		
		reset();
		cin >> ws;
		
		string str;
		while (getline(cin, str)) {
			istringstream read(str);

			string parStr, chldStr;
			read >> parStr;

			int par = getID(parStr);
			while (read >> chldStr) {
				int chld = getID(chldStr);
				isChild[chld] = true;

				adj[par].push_back(chld);
			}

			cin >> ws;
			if (isdigit(cin.peek()))
				break;
		}

		PAIR res = MP(0, 0);
		for (int i = 1; i <= n; i ++) {
			if (!isChild[i])
				inc(res, solve(i, 0));
		}

		cout << ++ tc << ". " << res.S << " " << res.F << " " << getCost(res) << "\n";
	}

return 0;
}