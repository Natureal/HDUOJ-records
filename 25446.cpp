////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-04 23:01:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1160KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string.h>
#include<cstdio>
#include<string>
#include<limits.h>
#include<queue>
#define N 20005
using namespace std;
typedef struct node
{
	int num;
	int len;
	int Next;
}Node;
int res,head[105],dis[105],n;
Node s[N];
typedef pair<int,int> pii;
void init()
{
	memset(head,-1,sizeof(head));
	res=0;
}
void add(int a,int b,int c)
{
	s[res].num=b;
	s[res].len=c;
	s[res].Next=head[a];
	head[a]=res++;
}
void dijstra()
{
	for(int i=1;i<=n;++i) dis[i]=(i==1)?0:INT_MAX;
	priority_queue<pii,vector<pii>,greater<pii> >Q;
	Q.push(make_pair(dis[1],1));
	while(!Q.empty())
	{
		pii u=Q.top();
		Q.pop();
		int x=u.second;
		if(u.first!=dis[x]) continue;
		for(int i=head[x];i!=-1;i=s[i].Next)
			if(dis[s[i].num]>dis[x]+s[i].len)
		     {
				dis[s[i].num]=dis[x]+s[i].len;
				Q.push(make_pair(dis[s[i].num],s[i].num));
			 }
	}
}
int main()
{
	int m;
	while(~scanf("%d%d",&n,&m))
	{
		init();
		if(!n&&!m) break;
		for(int i=0;i!=m;++i)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add(a,b,c);
			add(b,a,c);
		}
		dijstra();
		printf("%d\n",dis[n]);
	}return 0;
}