#include<bits/stdc++.h>
#define mp make_pair
using namespace std;

int N,i;
pair<int, string> arr[505];
string s;

int main()
{
	cin>>N;
	
	for (i=1;i<=N;i++)
	{
		cin>>s;
		arr[i]=mp(s.length(),s);
	}
	sort(arr+1, arr+N+1);
	
	for (i=1;i<=N;i++)
		cout<<arr[i].second<<"\n";
		
return 0;
}
