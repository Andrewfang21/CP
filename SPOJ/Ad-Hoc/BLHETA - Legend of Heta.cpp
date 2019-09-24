#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,i;
	string str,dummy;
	cin>>str;
	cin>>N;
	
	for (i=1;i<=N;i++)
	{
		cin>>dummy;
		
		while (str.find(dummy)>=0)
		{
			//cout<<str.find(dummy)<<" "<<str<<"\n";
			if (str.find(dummy)<str.length())
				str.erase(str.find(dummy),dummy.length());
			else
				break;
		}
	}
	cout<<"\n";
	cout<<str<<"\n";
return 0;
}
