#include<bits/stdc++.h>
using namespace std;
long long dp[100000005],memo[100000005];

long long check(long long num)
{
	char a;
	string b,temp;
	int res;
	
	temp=to_string(num);
	a=temp[0];	b=temp.substr(1,temp.length()-1);
	int lol=a-'0';
	
	if (temp.length()%2==0)	//genap
		res=lol+dp[stoi(b)];
	else
		res=-lol+dp[stoi(b)];
return res;
}

int main()
{
	int i,temp;
	memset(memo,0,sizeof(memo));
	for (i=1;i<=9;i++)
		dp[i]=-1*i;
	for (i=10;i<=pow(10,5);i++)
	{
		dp[i]=check(i);
		
		if (dp[i]==1)
			memo[i]=memo[i-1]+1;
		else
			memo[i]=memo[i-1];
	}
	int TC,a,b;
	
	cin>>TC;
	
	while (TC--)
	{
		cin>>a>>b;
		cout<<memo[b]-memo[a-1]<<"\n";
		for (i=a;i<=b;i++)
			if (dp[i]==1)
				cout<<i<<" ";
		cout<<"\n";
	}
return 0;
}
