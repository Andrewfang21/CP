#include<bits/stdc++.h>
using namespace std;

int main()
{
	string S,dummy,temp1,temp2,temp3,temp4;
	int TC;
	cin>>S;
	cin>>TC;
	int i;
	string arr[TC+5];
	dummy="*";
	
	for (i=1;i<=TC;i++)
	{
		cin>>arr[i];
		
		if (S.find(dummy)==0)
		{
			temp1=S.substr(1,S.length()-1);
			int b=arr[i].length()-temp1.length();
			if (b>=0)
			{
				temp2=arr[i].substr(arr[i].length()-temp1.length(),temp1.length());
						
				if (temp2==temp1) cout<<arr[i]<<"\n";
			}
		} else
		if (S.find(dummy)==S.length()-1)
		{
			temp1=S.substr(0,S.length()-1);
			if (arr[i].find(temp1)==0) cout<<arr[i]<<"\n";
		} else
		if (S=="*") cout<<arr[i]<<"\n"; else
		if ((S.find(dummy)>0)&&(S.find(dummy)<S.length()-1))
		{
			temp1=S.substr(0,S.find(dummy));
			temp2=S.substr(S.find(dummy)+1,S.length()-S.find(dummy)-1);
			
			temp3=arr[i].substr(0,temp1.length());
			string temp=arr[i];
			arr[i]=arr[i].erase(0,temp1.length());
			if (arr[i].length()>=temp2.length())
			{
				temp4=arr[i].substr(arr[i].length()-temp2.length(),temp2.length());
				if ((temp1==temp3)&&(temp2==temp4)) cout<<temp<<"\n";
			}
		}
	}
return 0;	
}
