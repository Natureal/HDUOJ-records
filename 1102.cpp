////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-19 13:48:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1102
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:396KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int n,m,father[1000],k;
struct edge
{
	int a,b,d;
}edges[100000];
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
		father[x]=y;
		return true;
	}
	return false;
}
void quick_sort(struct edge s[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r;
		struct edge x=s[l];
		while(i<j)
		{
			while(i<j && s[j].d>x.d)j--;
			if(i<j)s[i++]=s[j];
			while(i<j && s[i].d<=x.d)i++;
			if(i<j)s[j--]=s[i];
		}
		s[i]=x;
		quick_sort(s,l,i-1);
		quick_sort(s,i+1,r);
	}
	return;
}
void Kruskal()
{
	for(int i=1;i<=n;i++)father[i]=i;
	quick_sort(edges,1,k);
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		if(union_set(edges[i].a,edges[i].b))
		{
			sum+=edges[i].d;
		}
	}
	printf("%d\n",sum);
	return;
}
int main()
{
	int temp,a1,b1;
	while(scanf("%d",&n)!=EOF)
	{
		k=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&temp);
				if(temp!=0)
				{
					edges[k].a=i;
					edges[k].b=j;
					edges[k].d=temp;
					k++;
				}
			}
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a1,&b1);
			edges[k].a=a1;
			edges[k].b=b1;
			edges[k].d=0;
			k++;
		}
		k--;
		Kruskal();
	}
	return 0;
}