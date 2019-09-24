#include<bits/stdc++.h>
using namespace std;
int temp[8],save,dist[666668],hitung;
bool visited[666668];
struct lol
{
	int kondisi,step;
}u;
void rotate(string blah)
{
	int temp1[8];
	for (int i=1;i<=6;i++)
		temp1[i]=temp[i];
		
	if (blah=="timur")
	{
		temp[2]=temp1[4];
		temp[1]=temp1[6];
		temp[6]=temp1[2];
		temp[4]=temp1[1];	
	} else
	if (blah=="barat")
	{
		temp[1]=temp1[4];
		temp[2]=temp1[6];
		temp[6]=temp1[1];
		temp[4]=temp1[2];
	} else
	if (blah=="selatan")
	{
		temp[2]=temp1[5];
		temp[5]=temp1[1];
		temp[1]=temp1[3];
		temp[3]=temp1[2];
	} else
	if (blah=="utara")
	{
		temp[5]=temp1[2];
		temp[1]=temp1[5];
		temp[3]=temp1[1];
		temp[2]=temp1[3];
	}
}
void convert_num()
{
	hitung=0;
	int i;
	for (i=1;i<=6;i++)
	{
		hitung+=temp[i];
		if (i<6) hitung*=10;
	}
}
int main()
{
	string dummy;
	int i,P[8],a,target=0;
	getline(cin,dummy);
	for (i=1;i<=6;i++)
	{
		scanf("%d",&P[i]);
		save+=P[i];
		if (i<6) save*=10;
	}
	for (i=1;i<=6;i++)
	{
		cin>>a;
		target+=a;
		if (i<6) target*=10;
	}
	dist[save]=-1;
	queue<lol>q;
	q.push({save,dist[save]});
	while (!q.empty())
	{
		u=q.front();	q.pop();
		if (!visited[u.kondisi])
		{
			visited[u.kondisi]=true;
			dist[u.kondisi]=u.step+1;
		
			if (u.kondisi==target)
			{
				cout<<dist[u.kondisi]<<"\n";
				break;
			}
			int simpan=dist[u.kondisi];
			hitung=u.kondisi;
			for (i=1;i<=6;i++)
			{
				temp[6-i+1]=u.kondisi%10;
				u.kondisi/=10;
			}
			
			//menggelinding ke timur//
			rotate("timur");
			convert_num();
			q.push({hitung,simpan});
			rotate("barat");
			
			//menggelinding ke barat
			rotate("barat");
			convert_num();
			q.push({hitung,simpan});
			rotate("timur");
			
			//menggelinding ke selatan
			rotate("selatan");
			convert_num();
			q.push({hitung,simpan});
			rotate("utara");
			
			//menggelinding ke utara
			rotate("utara");
			convert_num();
			q.push({hitung,simpan});
			rotate("selatan");
		}
	}
return 0;
}
