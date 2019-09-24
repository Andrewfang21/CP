#include<bits/stdc++.h>
#define fi first
#define sec second
#define ll long long
using namespace std;
typedef pair<ll, ll> ii;
struct lol
{
	ii p1,p2;
}line[5],garis;
ll i;

ll area(ii a, ii b, ii c)
{
	long long temp = a.fi*(b.sec-c.sec)+b.fi*(c.sec-a.sec)+c.fi*(a.sec-b.sec);
	if (temp>0)
		return 1;
	else
	if (temp==0)
		return 0;
	else
		return -1;
}

bool inside(ii a, ii b, ii c)
{
	if (c.fi>=min(a.fi,b.fi) && c.fi<=max(a.fi,b.fi) && c.sec>=min(a.sec,b.sec) && c.sec<=max(a.sec,b.sec))
		return true;
return false;
}

bool check()
{
	ll boo1,boo2,boo3,boo4;
	boo1=area(line[i].p1,line[i].p2,garis.p1);
	boo2=area(line[i].p1,line[i].p2,garis.p2);
	boo3=area(garis.p1,garis.p2,line[i].p1);
	boo4=area(garis.p1,garis.p2,line[i].p2);
	
	if ((boo1!=boo2) && (boo3!=boo4))
		return true;
	
	if (boo1==0 && inside(line[i].p1,line[i].p2,garis.p1))
		return true;
	if (boo2==0 && inside(line[i].p1,line[i].p2,garis.p2))
		return true;
	if (boo3==0 && inside(garis.p1,garis.p2,line[i].p1))
		return true;
	if (boo4==0 && inside(garis.p1,garis.p2,line[i].p2))
		return true;
return false;
}

int main()
{
	ll N,x[4],y[4],a,b,c,d;
	cin>>N;
	for (ll it=1;it<=N;it++)
	{
		ll tmp=0;
		cin>>x[1]>>y[1]>>x[2]>>y[2]>>a>>b>>c>>d;

		garis.p1.fi=a;		garis.p1.sec=b;
		garis.p2.fi=c;		garis.p2.sec=d;
		
		line[0].p1.fi=x[1];		line[0].p1.sec=y[1];	line[0].p2.fi=x[2];		line[0].p2.sec=y[1];
		line[1].p1.fi=x[1];		line[1].p1.sec=y[1];	line[1].p2.fi=x[1];		line[1].p2.sec=y[2];
		line[2].p1.fi=x[1];		line[2].p1.sec=y[2];	line[2].p2.fi=x[2];		line[2].p2.sec=y[2];
		line[3].p1.fi=x[2];		line[3].p1.sec=y[2];	line[3].p2.fi=x[2];		line[3].p2.sec=y[1];
		
		bool ans=false;
		for (i=0;i<4;i++)
		{
			if (check())
				ans=true;
			if (inside(line[i].p1,line[i].p2,garis.p1) && inside(line[i].p1,line[i].p2,garis.p2))
				ans=true;
		}
		if (ans)	
			cout<<"YA\n";
		else
			cout<<"TIDAK\n";
	}
return 0;
}