////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-16 19:56:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int n,m;
int father[105];
struct edges
{
	int a,b;
	int w;
}edge[5000];

int find(int x)
{
	if(x!=father[x]) father[x]=find(father[x]);
	return father[x];
}

bool union_set(int u,int v)
{
	int x=find(u);
	int y=find(v);
	if(x!=y)
	{
		father[x]=y;
		return true;
	}
	return false;
}

void quick_sort(struct edges s[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r;
    	struct edges x=s[l];
		while(i<j)
		{
			while(i<j && s[j].w>=x.w) j--;
			if(i<j) s[i++]=s[j];
			while(i<j && s[i].w<x.w) i++;
			if(i<j) s[j--]=s[i];
		}
		s[i]=x;
		quick_sort(s,l,i-1);
		quick_sort(s,i+1,r);
	}
	return;
}

void kruskal()
{
	int count=0,sum=0;
	for(int i=1;i<=m;i++) father[i]=i;
	quick_sort(edge,1,n);
	for(int i=1;i<=n;i++)
	{
		if(union_set(edge[i].a,edge[i].b))
		{
			sum+=edge[i].w;
			count++;
		}
		if(count>=m-1) break;
	}
	if(count>=m-1) printf("%d\n",sum);
	else printf("?\n");
}

int main()
{
	while(scanf("%d",&n)!=EOF && n)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
		}
		kruskal();
	}
	return 0;
}