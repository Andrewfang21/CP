#include<bits/stdc++.h>
using namespace std;
bool is_prime[3000],counted[3000];

void sieve()
{
	int i,p,temp;
	i=2;
	is_prime[1]=false;
	while ((i*i)<=3000)
	{
		p=2;
		while ((i*p)<=3000)
		{
			is_prime[i*p]=false;
			p++;
		}
		i++;
		while (!is_prime[i])	i++;
	}
}

int main()
{
	vector<int>vec;
	int i,ans,j,temp,TC,num;
	bool found;
	
	memset(is_prime,true,sizeof(is_prime));
	sieve();
	vec.push_back(30);	vec.push_back(42);
	
	for (i=43;i<=2664;i++)
	{
		found=false;
		ans=0;
		for (j=2;j<=sqrt(i);j++)
		{
			if (i%j==0)
			{
				temp=i/j;
				if (is_prime[temp])
					ans++;
				if (is_prime[j])
					ans++;
				if ((is_prime[temp])&&(is_prime[j])&&(temp==j))
					ans--;
				
				if (ans>=3)
				{
					found=true;
					break;
				}
			}
		}
		if (found)
			vec.push_back(i);
	}
	sort(vec.begin(),vec.end());
	
	vector<int>::iterator it;
	for (it=vec.begin();it!=vec.end();it++)
	{
		if (!counted[*it])
			counted[*it]=true;
		else
		{
			vec.erase(it);
			it--;
		}
	}
	sort(vec.begin(),vec.end());
	
	/*for (int k=0;k<vec.size();k++)
		cout<<vec[k]<<"\n";*/
	
	cin>>TC;
	while (TC--)
	{
		cin>>num;
		cout<<vec[num-1]<<"\n";
	}
return 0;
}
