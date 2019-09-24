#include<bits/stdc++.h>
#define pf push_front
using namespace std;

deque<int>q[5];
string num;
int prevs=0,now=1,nexts=2,pos1,pos2,save,curr,it;

bool cek()
{
	for (int i=0;i<q[now].size();i++)
	{
		int c=num[i]-'0';
		if (q[now][i]!=c)
			return false;
	}
return true;
}

void debug()
{
	for (int i=0;i<q[prevs].size();i++)
		cout<<q[prevs][i];
	cout<<"\n";
	
	for (int i=0;i<q[now].size();i++)
		cout<<q[now][i];
	cout<<"\n\n";
	
//	for (int i=0;i<q[nexts].size();i++)
//		cout<<q[nexts][i];
//	cout<<"\n\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>num;
	q[prevs].pf(0);
	q[now].pf(1);
	it=2;		save=0;
	
//	cout<<"debug\n";
	while (true)
	{
		pos1=q[prevs].size()-1;		pos2=q[now].size()-1;
		save=0;
		
		if (pos1==pos2)
		{
			while (pos1>=0)
			{
				curr=q[prevs][pos1]+q[now][pos2];
//				cout<<q[prevs][pos1]<<" "<<q[now][pos2]<<"\n\n";
	
				q[nexts].pf((curr+save)%10);
				
				save=(curr+save)/10;
				pos1--;		pos2--;
			}
			if (save!=0)
				q[nexts].pf(save);
		}
		else
		{	//size q[now] pasti >= size q[nexts]
			while (pos2>=0)
			{
				if (pos1>=0)
				{
					curr=q[prevs][pos1]+q[now][pos2];
//					cout<<q[prevs][pos1]<<" "<<q[now][pos2]<<"\n\n";
				}
				else
				{
					curr=q[now][pos2];
//					cout<<q[prevs][pos2]<<"\n";
				}
					
				q[nexts].pf((curr+save)%10);
				
				save=(curr+save)/10;
				pos1--;		pos2--;
			}
			if (save!=0)
				q[nexts].pf(save);
				
		}
		swap(q[prevs],q[now]);
		swap(q[now],q[nexts]);
		q[nexts].clear();
		
		
		it++;
//		cout<<it<<":\n";
//		debug();
		
		if (q[now].size()>num.length())
		{
			cout<<"0\n";
			return 0;
		}
		else
		if (q[now].size()==num.length())
		{
	//		cout<<now<<"\n";
			if (cek())
			{
				cout<<it<<"\n";
				return 0;
			}
		}
	}
return 0;
}
