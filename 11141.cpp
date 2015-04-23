////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-01 14:33:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1114
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:300KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1114.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月01日 星期六 13时43分03秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#define MAXN 1000000000
int t,v,n,e,f,dp[10005]={0},p[505],w[505];
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int i,j,flag;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&e,&f);
		for(i=1;i<=f;i++)
		{
			dp[i]=MAXN;
		}
		v=f-e;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&p[i],&w[i]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=w[i];j<=v;j++)
			{
				dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
			}
		}
		if(dp[v]==MAXN)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",dp[v]);
	}
	return 0;
}