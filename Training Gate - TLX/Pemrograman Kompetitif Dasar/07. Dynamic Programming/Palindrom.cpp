#include<bits/stdc++.h>
using namespace std;
int best,i,N,memo[55][55],M;
string str;

int solve(int a, int b)
{
	int ret=0;
	if (a==b) return 1; else
	if ((str[a]==str[b])&&((a+1)==b)) return 2; else
	if (memo[a][b]!=0)  
	{
		return memo[a][b]; 
	}
	else
	if (str[a]==str[b])
		ret=2+solve(a+1,b-1);
	else
		ret=max(solve(a+1,b),solve(a,b-1));
	
	memo[a][b]=ret;
	return ret;	
}
int main()
{
	scanf("%d",&N);
	for (i=1;i<=N;i++)
	{
		cin>>str;
		memset(memo,0,sizeof(memo));
		M=str.length()-1;
		best=solve(0,M);
		cout<<best<<"\n";
	}
return 0;	
}
