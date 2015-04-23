////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-18 22:48:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1301
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
struct edge
{
	int v;
	int u;
	int w;
};
edge edges[10000];
int N,M;
int parent[1000];
int sum;
void UFset()
{
	int i;
	for(i=1;i<=N;i++)		
	{
		parent[i]=i;
	}
}
int Find(int a)
{
	if(parent[a]==a)
		return a;
	else
		return parent[a]=Find(parent[a]);
}
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
bool Union(int a,int b,int d)
{
	if(a==b)
		return 0;
	parent[a]=b;
	sum+=d;
	return 1;
}
void Kruskal()
{
	sum=0;
	int num=0;
	UFset();
	int i;
	sort(edges,edges+M,cmp);

	for(i=0;i<M;i++)
	{
		if(Union(Find(edges[i].v),Find(edges[i].u),edges[i].w))
		   num++;
	}
		printf("%d\n",sum);
}
int main()
{
	while(scanf("%d%*c",&N))
	{
		memset(edges,0,sizeof(edges));
		if(N==0)
			break;
		char top,end;
		int m,w;
		M=0;
		int i,j;
		int k=0;
		for(i=0;i<N-1;i++)
		{
			scanf("%c %d%*c",&top,&m);
			M=M+m;			
			for(j=0;j<m;j++)
			{
				if(j<m-1)
				    scanf("%c %d%*c",&end,&w);					
				else
					scanf("%c %d%*c",&end,&w);
				edges[k].v=top-64;
				edges[k].u=end-64;
				edges[k].w=w;
				k++;  //之前WA在这
				
			}
		}
	
		Kruskal();

	}
	return 0;
}