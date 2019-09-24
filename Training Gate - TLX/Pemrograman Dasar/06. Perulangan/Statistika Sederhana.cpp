#include<bits/stdc++.h>
using namespace std;
int N,arr[101],i;

int main()
{
	cin>>N;
	for (i=0;i<N;i++) cin>>arr[i];
	sort(arr,arr+N);
	cout<<arr[N-1]<<" "<<arr[0]<<"\n";
return 0;	
}
