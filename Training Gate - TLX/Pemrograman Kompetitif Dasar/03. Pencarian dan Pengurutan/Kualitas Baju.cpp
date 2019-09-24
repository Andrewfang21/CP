#include<bits/stdc++.h>
using namespace std;

int arr[100005];

int main()
{
	int N,i;
	
	cin>>N;
	for (i=1;i<=N;i++)
		cin>>arr[i];
		
	sort(arr+1, arr+N+1);
	
	double res=arr[N/2 + 1];
	
	if (N%2==0)
	{
		res=(arr[N/2]+arr[N/2 + 1])/2.0;
		cout<<setprecision(1)<<fixed<<res<<"\n";
	}
	else
		cout<<setprecision(1)<<fixed<<res<<"\n";
		
return 0;
}
