#include<bits/stdc++.h>
using namespace std;
int N,i,best,memo[2000];

int Solve(int a)
{
	int ret;
	if (memo[a]!=-1) return memo[a]; else
	if (a==0) return 0;
	else
	ret=max(a,Solve(a/2)+Solve(a/3)+Solve(a/4));
	memo[a]=ret;
	return ret;
}


int main()
{
	scanf("%d",&N);
	memset(memo,-1,sizeof(memo));
	best=Solve(N);
	cout<<best<<"\n";
return 0;	
}