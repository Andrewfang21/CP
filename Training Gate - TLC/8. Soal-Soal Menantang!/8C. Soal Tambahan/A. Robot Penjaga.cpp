#include<bits/stdc++.h>
#define fi first
#define sec second
#define mp make_pair
#define pb push_back
#define ll long long
using namespace std;

ll N,res,cnt,vis[12][12][12][12][12][2][2][2],row[5],pos[5],dir[5];
char maze[12][12];
bool kejepit[5];
vector<pair<ll,ll>>obs;

ll movex[]={0,0,0,1,-1};
ll movey[]={0,1,-1,0,0};

struct lol
{
	ll a,b,x,y,z,xa,ya,za,dist;
}u;

pair<ll, ll>start,abal;

bool inside(ll i, ll j)
{
	return (i>0 && i<=N && j>0 && j<=N);
}

bool cek(ll i)
{
	return (i>0 && i<=N);
}

bool ketabrak(ll i, ll j, ll tipe)
{		
	for(ll it=1;it<=cnt;it++)
		if (i==row[it] && j==pos[it])
			return true;
return false;
}

void reset()
{
	memset(vis,-1,sizeof(vis));
	memset(dir,0,sizeof(dir));
	memset(kejepit,false,sizeof(kejepit));
	
	for (ll i=0;i<obs.size();i++)
	{
		pair<ll, ll>curr=obs[i];
		if (maze[curr.fi][curr.sec+1]=='#' && maze[curr.fi][curr.sec-1]=='#')
			kejepit[i+1]=true;
	}
	
	while (obs.size()<3)
		obs.pb(mp(0,0));
}

void convert()
{
	abal.fi=u.a;		abal.sec=u.b;
	pos[1]=u.x;		pos[2]=u.y;		pos[3]=u.z;
	dir[1]=u.xa;	dir[2]=u.ya;	dir[3]=u.za;
}

void BFS()
{
	queue<lol>q;
	q.push({start.fi, start.sec, pos[1],pos[2],pos[3],dir[1],dir[2],dir[3],0});
	res=-1;
	
	while (!q.empty())
	{
		u=q.front();		q.pop();
		convert();
		
		bool proceed=true;
		if (vis[abal.fi][abal.sec][pos[1]][pos[2]][pos[3]][dir[1]][dir[2]][dir[3]]!=-1)
			continue;
		if (!inside(abal.fi,abal.sec))
			continue;
		if (maze[abal.fi][abal.sec]=='#')
			continue;
			
		for (ll i=1;i<=cnt;i++)
			if (ketabrak(abal.fi, abal.sec, i))
			{
				proceed=false;
				break;		
			}		
		if (!proceed)
			continue;
		
//		cout<<abal.fi<<" "<<abal.sec<<"  "<<row[1]<<" "<<pos[1]<<"    "<<u.dist<<"\n";
		
		vis[abal.fi][abal.sec][pos[1]][pos[2]][pos[3]][dir[1]][dir[2]][dir[3]]=u.dist;		
		
//		cout<<abal.fi<<" "<<abal.sec<<"   "<<row[1]<<" "<<pos[1]<<"         "<<u.dist<<"\n";
		
		if (maze[abal.fi][abal.sec]=='T')
		{
			res=u.dist;
			break;
		}
		
		ll block[5];
		for (ll j=1;j<=cnt;j++)
		{
			block[j]=pos[j];
			if (kejepit[j])
				continue;	
			else
			{	 
				ll temp;
				if (dir[j]==0)
					temp=pos[j]+1;
				else
					temp=pos[j]-1;						
				
				if (temp==0 || temp==N+1 || maze[row[j]][temp]=='#')
				{
					if (dir[j]==0)
						dir[j]=1;
					else
						dir[j]=0;
						
					if (dir[j]==1)
						temp=pos[j]-1;
					else
						temp=pos[j]+1;
				}
				pos[j]=temp;
			}
		}
			
		for (ll i=0;i<5;i++)
		{
			pair<ll, ll>nexts;
			nexts=mp(abal.fi+movex[i], abal.sec+movey[i]);	
			
			bool proceed=true;
			for (ll it=1;it<=3;it++)
				if (nexts.fi==row[it] && nexts.sec==block[it] && pos[it]==abal.sec)
				{
					proceed=false;
					break;
				}
				
			if (proceed)
				q.push({nexts.fi, nexts.sec, pos[1],pos[2],pos[3],dir[1],dir[2],dir[3],u.dist+1});	
		}	
	}
}

void read()
{
	cin>>N;
	
	cnt=0;
	for (ll i=1;i<=N;i++)
		for (ll j=1;j<=N;j++)
		{
			cin>>maze[i][j];
			if (maze[i][j]=='S')
				start=mp(i,j);
			if (maze[i][j]=='X')
			{
				cnt++;
				row[cnt]=i;
				pos[cnt]=j;
				obs.pb(mp(i,j));
			}
		}
}

int main()
{
	ios_base::sync_with_stdio(false);

	memset(row,0,sizeof(row));
	memset(pos,0,sizeof(pos));
	read();
	reset();
	BFS();
	
	cout<<res<<"\n";
return 0;
}