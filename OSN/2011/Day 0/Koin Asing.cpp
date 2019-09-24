#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int i;
	map<char,int>koin;
	cin>>s;
	for (i=0;i<s.length();i++)
		koin[s[i]]++;
	for (i=0;i<s.length();i++)
		if (koin[s[i]]==1)
		{
			cout<<i+1<<"\n";
			return 0;
		}
return 0;
}
