////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-16 18:38:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int n,m,father[105];

struct edges
{
	int a,b;
	int w;
}edge[5000];
int find(int x)
{
	if(father[x]!=x) father[x]=find(father[x]);
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
			while(i<j && s[j].w>x.w) j--;//s中等于x的元素放在右边
			if(i<j) s[i++]=s[j];
			
			while(i<j && s[i].w<=x.w) i++;
			if(i<j) s[j--]=s[i];
		}
		s[i]=x;
		quick_sort(s,l,i-1);
		quick_sort(s,i+1,r);
	}
	return;
}

void Kruskal()
{
	for(int i=1;i<=n;i++)
	{ father[i]=i; }
	quick_sort(edge,1,m);
	int sum=0;
	for(int i=1;i<=m;i++)
	{
		if(union_set(edge[i].a,edge[i].b))
		{
			sum+=edge[i].w;
		}
	}
	printf("%d\n",sum);
}

int main()
{
	while(scanf("%d",&n)!=EOF && n)
	{
		m=n*(n-1)/2;
		for(int i=1;i<=m;i++)
		{
			scanf("%d %d %d",&edge[i].a,&edge[i].b,&edge[i].w);
		}
		Kruskal();
	}
	return 0;
}