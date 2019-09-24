#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int Q,rev,i,num;
	string command;
	deque<int>vec;
	rev=0;
	cin>>Q;
	
	for (i=1;i<=Q;i++)
	{
		cin>>command;
		if ((command=="toFront")||(command=="push_back"))
		{
			cin>>num;
			if (rev==0)	//belum direverse
			{
				if (command=="toFront")	vec.push_front(num);
				else
				if (command=="push_back")	vec.push_back(num);
			}
			else
			if (rev==1)	//udh di reverse
			{
				if (command=="toFront")	vec.push_back(num);
				else
				if (command=="push_back")	vec.push_front(num);
			}
		}
		else
		{
			if (command=="front")
			{
				if (vec.empty())
					cout<<"No job for Ada?\n";
				else
				{
					if (rev==0)
					{
						cout<<vec.front()<<"\n";
						vec.pop_front();
					}
					else
					if (rev==1)
					{
						cout<<vec.back()<<"\n";
						vec.pop_back();
					}
				}
			}
			else
			if (command=="back")
			{
				if (vec.empty())
					cout<<"No job for Ada?\n";
				else
				{
					if (rev==0)
					{
						cout<<vec.back()<<"\n";
						vec.pop_back();
					}
					else
					{
						cout<<vec.front()<<"\n";
						vec.pop_front();
					}
				}
			}
			else
			if (command=="reverse")
			{
				if (rev==0)	rev=1; else rev=0;
			}
		}
	}
return 0;
}
