#include<bits/stdc++.h>
using namespace std;
string jawaban;
int main()
{
	cout<<"?\n";
	cout<<"1 2\n";
	cout<<"3 4\n";
	fflush(stdout);
	cin>>jawaban;
	
	if (jawaban=="SEIMBANG")
	{
		cout<<"?\n5 6\n7 8\n";
		fflush(stdout);
		cin>>jawaban;
		
		if (jawaban=="KIRI")
		{
			cout<<"?\n1 5\n2 3\n";
			fflush(stdout);
			cin>>jawaban;
			if (jawaban=="SEIMBANG")
			{
				cout<<"! 6\n";
				fflush(stdout);
				return 0;
			} else
			{
				cout<<"! 5\n";
				fflush(stdout);
				return 0;
			}
		}
		else
		if (jawaban=="KANAN")
		{
			cout<<"?\n";
			cout<<"1 7\n";
			cout<<"2 3\n";
			cin>>jawaban;
			
			if (jawaban=="SEIMBANG")
			{
				cout<<"! 8\n";
				fflush(stdout);
				return 0;
			} else
			{
				cout<<"! 7\n";
				fflush(stdout);
				return 0;
			}
		}
	}
	else
	if (jawaban=="KIRI")
	{
		cout<<"?\n1 3\n4 5\n";
		fflush(stdout);
		cin>>jawaban;
		
		if (jawaban=="KIRI")
		{
			cout<<"! 1\n";
			fflush(stdout);
			return 0;
		}
		else
		{
			cout<<"! 2\n";
			fflush(stdout);
			return 0;
		}
	}
	else
	if (jawaban=="KANAN")
	{
		cout<<"?\n3 5\n6 7\n";
		fflush(stdout);
		cin>>jawaban;
		if (jawaban=="KIRI")
		{
			cout<<"! 3\n";
			fflush(stdout);
			return 0;
		}
		else
		{
			cout<<"! 4";
			fflush(stdout);
			return 0;
		}
	}
return 0;
}
