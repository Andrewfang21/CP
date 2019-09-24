#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int TC,ans,cnt,i;
	string s;
	cin>>TC;
	
	while (TC--)
	{
		cin>>s;
		int pref[s.length()+5];
		memset(pref,0,sizeof(pref));
		ans=cnt=0;
		
		if (s[0]=='K')
		{
			pref[0]=1;
			cnt++;
		}
		else
			pref[0]=0;
			
		for (i=1;i<s.length();i++)
		{
			if (s[i]=='K')
			{
				pref[i]=pref[i-1]+1;
				cnt++;
			}
			else
				pref[i]=pref[i-1];
		}
		
		for (i=0;i<s.length();i++)
		{
			if (s[i]=='E')
				ans=ans+((cnt-pref[i])*pref[i]);
		}
		/*for (i=0;i<s.length();i++)
			cout<<i<<" "<<pref[i]<<"\n";*/
			
		cout<<ans<<"\n";
	}
}
