#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

int N,val,i,num;
pair<int, int>arr[1005];

int main()
{
	cin>>N>>val;
	
	for (i=1;i<=N;i++)
	{
		cin>>num;
		arr[i]=mp(abs(val-num),num);
	}
	sort(arr+1, arr+N+1);
	
	cout<<arr[1].second<<"\n";
	
return 0;
}
