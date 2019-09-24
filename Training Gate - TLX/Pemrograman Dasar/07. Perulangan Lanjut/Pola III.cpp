#include<bits/stdc++.h>
using namespace std;
int N,i,j,save;

int main()
{
	save=0;
	cin>>N;
	for (i=1;i<=N;i++)
	{
		for (j=1;j<=i;j++)
		{
			if(save!=10) cout<<save; else 
			{
				save=0;
				cout<<save;	
			}
			save++;
		}
		cout<<"\n";
	}
return 0;	
}
