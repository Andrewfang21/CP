#include<bits/stdc++.h>
using namespace std;
int N,i,j,num;
bool has[1000001];

int main()
{
	cin>>N; i=2; has[1]=true;
	while((i*i)<=1000000)
	{
		j=2;
		while(i*j<=1000000)
		{
			has[i*j]=true;
			j++;
		}
		i++;
		while(has[i]) i++;		
	}
	for(i=1;i<=N;i++)
	{
		cin>>num;
		if(has[num]) cout<<"BUKAN\n"; else cout<<"YA\n";
	}
return 0;
}
