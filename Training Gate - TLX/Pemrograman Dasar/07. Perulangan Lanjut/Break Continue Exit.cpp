#include<bits/stdc++.h>
using namespace std;
int N,i;

int main()
{
	cin>>N;
	for (i=1;i<=N;i++)
	{
		if (i%10!=0)
		{
			if(i!=42) cout<<i<<"\n"; else
			{
				cout<<"ERROR"<<"\n";
				break;
			}
		}
	}
}
