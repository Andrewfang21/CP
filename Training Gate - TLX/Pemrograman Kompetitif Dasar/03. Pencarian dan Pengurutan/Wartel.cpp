#include<bits/stdc++.h>
using namespace std;

map<string, string> arr;

int main()
{
	int N,Q;
	string a,b;
	
	cin>>N>>Q;
	
	for (int i=1;i<=N;i++)
	{
		cin>>a>>b;
		arr[a]=b;
	}
	
	for (int i=1;i<=Q;i++)
	{
		cin>>a;
		
		if (arr[a]=="")
			cout<<"NIHIL\n";
		else
			cout<<arr[a]<<"\n";
	}
}
