#include<bits/stdc++.h>
using namespace std;

int main () {
	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc ++) {
		string S;		cin >> S;

		int status, segLen;
		vector<pair<int, int> > V;
		for (int i = 0; i < S.length(); i ++) {
			if (i == 0) {
				if (S[i] == '.')
					status = 0;
				else status = 1;

				segLen = 1;
				continue;
			}

			if (S[i] == '.') {
				if (status == 0)
					segLen ++;
				else {
					V.push_back(make_pair(segLen, status));
					status = 0;
					segLen = 1;
				}
			} else {
				if (status == 1)
					segLen ++;
				else {
					V.push_back(make_pair(segLen, status));
					status = 1;
					segLen = 1;	
				}
			}
		}
		V.push_back(make_pair(segLen, status));

		cout << "Kasus #" << tc << ": ";
		for (int i = 0; i < V.size(); i ++) {
			if (V[i].second == 0) {
				for (int j = 1; j <= V[i].first; j ++)
					cout << ".";
			}
			else {
				for (int j = 1; j <= V[i].first; j ++) {
					if (j == (V[i].first / 2 + 1) && V[i].first % 2 != 0) {
						cout << "X";
						continue;
					}
					cout << ".";
				}
			}
		}

		cout << "\n";
		V.clear();
	}

return 0;
}