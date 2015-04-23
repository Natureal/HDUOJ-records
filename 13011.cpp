////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-19 13:20:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1301
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
//#include <stdio.h>
//#include <string.h>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int n,father[100];
int count,num,m,a,b,count_e;
struct edge
{
	int a,b;
	int cost;
}edges[500];
bool cmp(edge a,edge b)
{
	return a.cost<b.cost;
}
void quick_sort(struct edge s[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r;
		struct edge x=s[l];
		while(i<j)
		{
			while(i<j&&s[j].cost>x.cost)j--;
			if(i<j)s[i++]=s[j];

			while(i<j&&s[i].cost<=x.cost)i++;
			if(i<j)s[j--]=s[i];
		}
		s[i]=x;
		quick_sort(s,l,i-1);
		quick_sort(s,i+1,r);
	}
	return;
}
int find(int x)
{
	if(father[x]!=x)father[x]=find(father[x]);
	return father[x];
}
bool union_set(int u,int v)
{
	int x=find(u);
	int y=find(v);
	if(x!=y)
	{
		father[y]=x;//¿É¸ÄÎªfather[y]=x;
		return true;
	}
	else return false;
}
void Kruskal()
{
	int i;
	for(i=1;i<=n+1;i++)father[i]=i;//init;
	//quick_sort(edge,1,m);
	sort(edges,edges+m,cmp);
	int sum=0;
	for(i=0;i<count_e;i++)
	{
		if(union_set(edges[i].a,edges[i].b))
		{
			sum+=edges[i].cost;
		}
	}
	printf("%d\n",sum);
}
int main()
{
	while(scanf("%d%*c",&n)!=EOF && n)
	{
		int d;
		char top,end;
		m=0;
		n--;
		count_e=0;
		memset(edges,0,sizeof(edges));
		for(int ii=0;ii<n;ii++)
		{
			scanf("%c %d%*c",&top,&num);
			m+=num;
			for(int j=0;j<num;j++)
			{
				scanf("%c %d%*c",&end,&d);
				edges[count_e].a=top-64;
				edges[count_e].b=end-64;
				edges[count_e].cost=d;
				count_e++;
			}
		}
		Kruskal();
	}
	return 0;
}