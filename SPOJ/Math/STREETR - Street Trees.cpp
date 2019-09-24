#include<bits/stdc++.h>
using namespace std;
int N,i,now,temp;
long long cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>N;
	int arr[N+5];
	
	for (i=1;i<=N;i++)
		cin>>arr[i];
	now=__gcd(arr[2]-arr[1],arr[3]-arr[2]);

	for (i=4;i<=N;i++)
		now=__gcd(now,arr[i]-arr[i-1]);
	
	cnt=0;
	for (i=2;i<=N;i++)
	{
		temp=arr[i]-arr[i-1];
		cnt+=((temp/now)-1);
	}
	cout<<cnt<<"\n";
return 0;
}
