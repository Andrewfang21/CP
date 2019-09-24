#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long N,TC,temp,ans;
	
	cin>>TC;
	
	while (TC--)
	{
		cin>>N;
		temp=sqrt(N);
		ans=temp*temp;
		
		if (ans==N)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}		
return 0;
}
