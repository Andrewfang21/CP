#include<bits/stdc++.h>
using namespace std;
float num;

int main()
{
	cin>>num;
	if (num==1) cout<<"ya\n"; else
	{
		while(num>2)
		{
		 num/=2;
		}
	if (num==2) cout<<"ya\n"; else cout<<"bukan\n";
	}
return 0;	
}
