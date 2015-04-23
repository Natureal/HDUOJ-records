////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-23 15:39:34
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1829
////Problem Title: 
////Run result: Accept
////Run time:812MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1829.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: Sun 23 Feb 2014 02:10:49 PM CST
 ************************************************************************/

#include<stdio.h>
int father[2005],t,n,m,sex[2005];
int find(int x)
{
	if(father[x]!=x)father[x]=find(father[x]);
	return father[x];
}
void  union_set(int u,int v)
{
	int x=find(father[u]);
	int y=find(father[v]);
	if(x==y)return;
	father[y]=x;
	return;
}
int main()
{
	int x,y,i,flag,ti;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++)
	{
		flag=1;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			father[i]=i;
			sex[i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&x,&y);
			if(find(x)==find(y))
			{
				flag=0;
				continue;
			}
			if(sex[x]==0)
				sex[x]=y;
			else
			{
				union_set(sex[x],y);
			}
			if(sex[y]==0)
				sex[y]=x;
			else
			{
				union_set(x,sex[y]);
			}
		}
		printf("Scenario #%d:\n",ti);
		if(flag)
			printf("No suspicious bugs found!\n\n");
		else
			printf("Suspicious bugs found!\n\n");
	}
	return 0;
}