#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int i,temp,ans,tc=0;
	
	while (cin>>s)
	{
		tc++;
		if (s=="---")	return 0;
		temp=ans=0;
		
		for (i=0;i<s.length();i++)
		{
			if (s[i]=='{')	temp++;
			if (s[i]=='}')	temp--;
			if (temp<0)
			{
				ans++;
				temp-=2;
			}
			if (temp>s.length()-i)
			{
				ans++;
				temp+=2;
			}
		}
		printf("%d. %d\n",tc,ans);
	}
return 0;
}
