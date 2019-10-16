#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N,a,i,temp;
	vector<int>vec,daftar;
	stack<int>st;
	bool found;
	
	while (cin>>N)
	{
		vec.clear();	daftar.clear();
		if (N==0)	return 0;
		for (i=0;i<N;i++)
		{
			cin>>a;
			vec.push_back(a);
		}
		temp=1;
		for (i=0;i<vec.size();i++)
		{
			if (!st.empty())
			{
				while (!st.empty())
				{
					//cout<<i<<"\n";
					if (!daftar.empty())
					{
						if (daftar[daftar.size()-1]-st.top()==-1)
						{
							daftar.push_back(st.top());
							st.pop();
						}
						else
							break;
					}
					else
						break;
				}
			}
			if (vec[i]!=temp)
			{
				st.push(vec[i]);
			}	
			if (vec[i]==temp)
			{
				daftar.push_back(temp);
				temp++;
			}
		}
		
		while (!st.empty())
		{
			daftar.push_back(st.top());
			st.pop();
		}
		found=false;
		for (i=0;i<daftar.size();i++)
		{
			if (daftar[i]!=i+1)
				found=true;
		}
		
		if (found)
			cout<<"no\n";
		else
			cout<<"yes\n";
			
		/*for (i=0;i<daftar.size();i++)
			cout<<daftar[i]<<" ";
		cout<<"\n";*/
	}
return 0;
}
