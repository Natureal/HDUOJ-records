////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-08 22:49:28
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1878
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1878.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月08日 星期六 22时28分12秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int fa[1005];
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void union_set(int u,int v)
{
	int x=find(u);
	int y=find(v);
	if(x!=y)
	{
		fa[y]=x;
	}
	return;
}
int main()
{
	int n,m,i,j,arr[1005],a,b,father;
	while(scanf("%d",&n)!=EOF && n)
	{
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			arr[i]=0;
			fa[i]=i;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			union_set(a,b);
			arr[a]++;
			arr[b]++;
		}
		father=find(1);
		for(i=1;i<=n;i++)
		{
			if(arr[i]%2==1||fa[i]!=father)
			{
				printf("0\n");
				break;
			}
		}
		if(i>n)
			printf("1\n");
	}
	return 0;
}