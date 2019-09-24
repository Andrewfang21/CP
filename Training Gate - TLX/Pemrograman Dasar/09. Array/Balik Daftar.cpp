#include<bits/stdc++.h>
using namespace std;
int arr[101],i,j,k;

int main()
{
	i=1;
	while(cin>>k)
	{
		arr[i]=k;
		i++;
	}
	for (j=i-1;j>=1;j--) cout<<arr[j]<<"\n";
return 0;	
}
