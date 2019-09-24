#include<bits/stdc++.h>
using namespace std;

int main()
{
	int TC,num,i;
	vector<int>vec;
	cin>>TC;
	
	while (TC--)
	{
		cin>>num;
		if (num==0)
			cout<<"10\n";
		else
		if (num<10)
			cout<<num<<"\n";
		else
		{
			for (i=9;i>=2;i--)
			{
				if ((num%i==0)&&(num!=0))
				{
					while (num%i==0)
					{
						vec.push_back(i);
						num/=i;
					}
				}
			}
			if (num!=1)
				vec.push_back(num);
			sort(vec.begin(),vec.end());
			bool found=false;
			
			for (i=0;i<vec.size();i++)
				if (vec[i]>9)
				{
					found=true;
					break;
				}
				
			if (!found)
			{
				for (i=0;i<vec.size();i++)
				cout<<vec[i];
					cout<<"\n";
			}
			else
				cout<<"-1\n";
			vec.clear();
		}
	}
return 0;
}
