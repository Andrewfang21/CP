#include<bits/stdc++.h>
using namespace std;
map<char,bool>asked;
map<char,int>cnt;
string ans,direction;
deque<char>q;
int N,K,frek;

void print_right();
void print_left();

void print()
{
	for (int i=0;i<q.size();i++)
	{
		for (int j=1;j<=cnt[q[i]];j++)
			cout<<q[i];
	}
}

void print_left()
{
	ans="TIDAK";
	for (char i='A';i<='Z';i++)
	{
		if (q.size()==frek)
			break;
		if ((cnt[i]>0)&&(!asked[i]))
		{
			cout<<"TANYA ";
			for (int j=1;j<=cnt[i];j++)
				cout<<i;
			print();
			cout<<"\n";
			fflush(stdout);
			
			cin>>ans;
			if (ans=="YA")
			{
				asked[i]=true;
				q.push_front(i);
				break;
			}
		}
		if ((i=='Z')&&(ans=="TIDAK"))
		{
			direction="right";
			print_right();
		}
	}
}

void print_right()
{
	ans="TIDAK";
	for (char i='A';i<='Z';i++)
	{
		if (q.size()==frek)
			break;
		if ((cnt[i]>0)&&(!asked[i]))
		{
			cout<<"TANYA ";
			print();
			for (int j=1;j<=cnt[i];j++)
				cout<<i;
			cout<<"\n";
			fflush(stdout);
			
			cin>>ans;
			if (ans=="YA")
			{
				asked[i]=true;
				q.push_back(i);
				break;
			}
		}
		if ((i=='Z')&&(ans=="TIDAK"))
		{
			direction="left";
			print_left();
		}
	}
}

int check(int num, char letter)
{
	cout<<"TANYA ";
	for (int i=1;i<=num;i++)
		cout<<letter;
	cout<<"\n";
	fflush(stdout);
	
	cin>>ans;
	if (ans=="YA")
		return num;
	else
		return -1;
}

int binser(char letter)
{
	int kiri,kanan,mid,up;
	kiri=2;		kanan=N;
	up=-1;
		
	while (kiri<=kanan)
	{
		mid=(kiri+kanan)/2;
		int temp=check(mid,letter);
		
		if (temp==-1)
			kanan=mid-1;
		else
		{
			up=mid;
			kiri=mid+1;
		}
	}
return up;
}

int main()
{
	ios_base::sync_with_stdio(false);
	string dummy;
	cin>>dummy;
	cin>>N>>K;
	frek=0;
	
	if (dummy[1]=='1')
	{
		cout<<"JAWAB BBBCAAAAAA\n";
		fflush(stdout);
	}
	else
	if (dummy[3]=='3')
	{
		direction="right";
		asked['A']=true;
		q.push_back('A');
		frek=N;
		
		for (char j='A';j<='Z';j++)
			cnt[j]=1;
		
		for (int i=1;i<=K;i++)
		{
			if (direction=="right")
				print_right();
			else
				print_left();
		
			if (q.size()==frek)
			{
				cout<<"JAWAB ";
				print();
				cout<<"\n";
				fflush(stdout);
				return 0;
			}
		}
	}
	else
	{
		direction="right";
		
		for (char j='A';j<='Z';j++)
		{
			cout<<"TANYA "<<j<<"\n";
			fflush(stdout);
			
			cin>>ans;
			if (ans=="YA")
			{
				cnt[j]=1;
				int x=binser(j);
				
				if (x>0)
				{
					cnt[j]=x;
					N-=x;
				}
				frek++;
				
				if (q.empty())
				{
					q.push_back(j);
					asked[j]=true;
				}
			}
		}
		
		for (int i=1;i<=K;i++)
		{
			if (direction=="right")
				print_right();
			else
				print_left();
			
			if (q.size()==frek)
			{
				cout<<"JAWAB ";
				print();
				cout<<"\n";
				fflush(stdout);
				return 0;
			}
		}
	}
return 0;
}
