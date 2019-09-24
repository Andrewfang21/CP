#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string subs;
	cin>>subs;
	int N,Q,i,temp;
	cin>>N>>Q;
	char str[N+5],now[N+5];
	int pref[N+5];
	memset(pref,0,sizeof(pref));
	temp=1;
	for (i=1;i<=N;i++)
	{
		cin>>str[i];
		if (str[i]==str[i-1])
			pref[i]=pref[i-1];
		else
		{
			pref[i]=pref[i-1]+1;
			now[temp]=str[i];
			temp++;
		}
	}
	/*for (i=1;i<=N;i++)
		cout<<pref[i]<<" ";
	cout<<"\n";*/
	
	for (i=1;i<=Q;i++)
	{
		int a,b;
		cin>>a>>b;
		if ((pref[b]-pref[a]+1)>=10)
			cout<<pref[b]-pref[a]+1<<"\n";
		else
		{
			int res=pref[b]-pref[a]+1;
			cout<<res<<" ";
			for (int j=pref[a];j<=pref[b];j++)
				cout<<now[j];
			cout<<"\n";
		}
	}
}
