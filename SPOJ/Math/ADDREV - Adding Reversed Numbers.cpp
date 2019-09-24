#include<bits/stdc++.h>
using namespace std;

int main()
{
	int TC,select;
	string a,b;
	cin>>TC;
	
	while (TC--)
	{
		cin>>a>>b;
		reverse(a.begin(),a.end());		reverse(b.begin(),b.end());
		int temp1,temp2,sum;
		temp1=stoi(a);	temp2=stoi(b);
		sum=temp1+temp2;
		
		a=to_string(sum);
		reverse(a.begin(),a.end());
		
		for (int temp=0;temp<a.length();temp++)
			if (a[temp]!='0')
			{
				select=temp;
				break;
			}
		for (int temp=select;temp<a.length();temp++)
			cout<<a[temp];
		cout<<"\n";
	}
return 0;
}
