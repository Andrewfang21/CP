#include<bits/stdc++.h>
using namespace std;
int TC,num,i,j,hitung;
string command;
deque<int>Lol;

int main()
{
	cin>>TC;
	for (i=1;i<=TC;i++)
	{
		cin>>command;
		if (command=="push_back")
		{
			cin>>num;
			Lol.push_back(num);
		} else
		if (command=="push_front")
		{
			cin>>num;
			Lol.push_front(num);
		} else
		if (command=="pop_back")
		{
			Lol.pop_back();
		} else
			Lol.pop_front();
	}
	while(!Lol.empty())
	{
		cout<<Lol.front()<<"\n";
		Lol.pop_front();
	}	
}

