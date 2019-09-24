#include<bits/stdc++.h>
using namespace std;

bool check(long long x)
{
	int i,cnt=0;
	
	if (x==1)
		return false;
	for (i=2;i<=sqrt(x);i++)
	{
		if (x%i==0)
			return false;
	}
return true;
}

int main()
{
	long long TC,a,b,i;
	bool yes;
	vector<long long>ans;
	cin>>TC;
	
	while (TC--)
	{
		cin>>a>>b;
		
		for (i=a;i<=b;i++)
		{
			yes=false;
			yes=check(i);
			if (yes)
				ans.push_back(i);
		}
		for (i=0;i<ans.size();i++)
			cout<<ans[i]<<"\n";
		ans.clear();
	}
}
