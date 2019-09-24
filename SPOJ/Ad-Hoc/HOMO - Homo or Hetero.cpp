#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL Q;

set <LL> S;
map <LL, LL> frek;

int main ()
{
	ios_base::sync_with_stdio(false);

	cin >> Q;

	LL num, val = 0;
	bool homo, hetero;

	while (Q --)
	{
		string query;
		cin >> query >> num;

		homo = hetero = false;

		if (query == "insert")
		{
			S.insert(num);
			frek[num] ++;

			val ++;
		}
		else
		{
			if (frek[num] == 1)
				S.erase(num);

			if (frek[num] > 0)
			{
				frek[num] --;
				val --;
			}
		}

		if (S.size() > 1)
			hetero = true;

		if (S.size() < val)
			homo = true;

		if (hetero && homo)		
			cout << "both\n";
		else
		if (hetero)
			cout << "hetero\n";
		else
		if (homo)
			cout << "homo\n";
		else
			cout << "neither\n";
	}
return 0;
}