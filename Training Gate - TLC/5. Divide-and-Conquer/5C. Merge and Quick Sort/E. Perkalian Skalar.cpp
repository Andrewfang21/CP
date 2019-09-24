#include<bits/stdc++.h>
#define ull long long
using namespace std;

int main()
{
	ull N,i,x,y;
	cin>>N;
	vector<ull>vec1,vec2;
	for (i=0;i<N;i++)
	{
		cin>>x;
		vec1.push_back(x);
	}
	for (i=0;i<N;i++)
	{
		cin>>y;
		vec2.push_back(y);
	}
	sort(vec1.begin(),vec1.end());	sort(vec2.begin(),vec2.end());	
	
	ull temp=0,b=0;
	for (i=0;i<N;i++) 
	{
		temp=vec1[i]*vec2[N-i-1];
		b=b+temp;
	}
	cout<<b<<"\n";
return 0;	
}