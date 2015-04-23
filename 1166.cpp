////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-01 10:49:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:520KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1166.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月28日 星期五 22时27分03秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
using namespace std;
int a,n,k,t,i,c[50005],ci[1000000];
int lowbit(int x)
{
	return (x&-x);
}
int sum(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}
void add(int x,int d)
{
	while(x<=n)
	{
		c[x]=c[x]+d;
		x+=lowbit(x);
	}
	return;
}
int main()
{
	char temp[10];
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			add(i,a);
		}
		int A,B;
		printf("Case %d:\n",k);
		while(scanf("%s",temp))
		{
			if(strcmp(temp,"End")==0)
			{
				break;
			}
			else
			{
				scanf("%d%d",&A,&B);
			}
			if(strcmp(temp,"Query")==0)
			{
				printf("%d\n",sum(B)-sum(A-1));
			}
			else if(strcmp(temp,"Sub")==0)
			{
				add(A,-B);
			}
			else if(strcmp(temp,"Add")==0)
			{
				add(A,B);
			
			}
		}
	}
	return 0;
}