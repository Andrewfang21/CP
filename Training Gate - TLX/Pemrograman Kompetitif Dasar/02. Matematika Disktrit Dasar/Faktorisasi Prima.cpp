#include<bits/stdc++.h>
using namespace std;
int num,temp,i,base[100],power[100];

int main()
{
	cin>>num; i=2;
	while(num!=1)
	{
		if (num%i==0) temp++;
		while (num%i==0)
		{
			num/=i;
			base[temp]=i;
			power[temp]++;
		}
		i++;
	}
	for (i=1;i<=temp;i++)
	{
		if (i==temp)
		{
			if (power[temp]!=1) cout<<base[temp]<<"^"<<power[temp]<<"\n"; else
			cout<<base[temp]<<"\n";
		} else
		if (power[i]!=1) cout<<base[i]<<"^"<<power[i]<<" x "; else
		cout<<base[i]<<" x ";
	}
return 0;	
}
