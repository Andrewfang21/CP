#include<bits/stdc++.h>
using namespace std;

int N;
string S;
deque<char> Q;

char vowels[] = {'A', 'I', 'U', 'E', 'O', 'a', 'i', 'u', 'e', 'o'};

void read() {
	cin >> N;
	cin.ignore();
	getline(cin, S);

	for (int i = 0; i < N; i ++)
		Q.push_back(S[i]);
}

bool vowel(char X) {
	for (int i = 0; i < 10; i ++) {
		if (X == vowels[i])
			return true;
	}

return false;
}

void solve() {
	while (true) {
		if (Q.empty())		break;

		char frontChar = Q.front();
		if (!vowel(frontChar))
			Q.pop_front();
		else
			break;
	}

	while (true) {
		if (Q.empty())		break;

		char backChar = Q.back();
		if (!vowel(backChar))
			Q.pop_back();
		else
			break;
	}

	for (int i = 0; i < Q.size(); i ++)
		cout << Q[i];
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);

	read();
	solve();

return 0;
}