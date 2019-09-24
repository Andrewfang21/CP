#include<bits/stdc++.h>
using namespace std;

const int N = 35;

int n;
char alpha[N], CH[5] = {'!', '?', '.', ',', ' '};
string s;

vector<char> Q;

bool tandaBaca (int pos) {
	for (int i = 0; i < 5; i ++) {
		if (CH[i] == s[pos])
			return true;
	}

return false;
}

int pangkat (int base, int power) {
	if (power == 0)
		return 1;
	if (power == 1)
		return base;

	int temp = pangkat(base, power / 2);

	if (power % 2 == 0) {
		return temp * temp;
	}

return temp * temp * base;
}

char getChar (int sum) {
	int res = 0, power = 0;
	while (sum != 0) {
		res = res + (sum % 10) * pangkat(n, power); 
		power ++;

		sum /= 10;
	}

return alpha[res];
}

int main () {
	ios_base::sync_with_stdio(false);
	cin >> n;

	cin.ignore();
	getline(cin, s);

	for (char i = 'A'; i <= 'Z'; i ++) {
		alpha[i - 'A' + 1] = i;
	}

	int pos = 0, sum = 0;
	while (pos < s.length()) {
		if (s[pos] == '/') {
			if (sum != 0) {
				char num = getChar(sum);
				Q.push_back(num);

				sum = 0;
			}
		}
		else if (s[pos] == '#') {
			Q.push_back('\n');
		} 
		else if (tandaBaca(pos)) {
			Q.push_back(s[pos]);
		}
		else {
			int currNum = s[pos] - '0';
			sum = sum * 10 + currNum;
		}

		pos ++;
	}

	if (sum != 0) {
		char num = getChar(sum);
		Q.push_back(num);

		sum = 0;
	}

	for (int i = 0; i < Q.size(); i ++) {
		i == Q.size() - 1 ? cout << Q[i] << "\n" : cout << Q[i];
	}
	
return 0;
}
