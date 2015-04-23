////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-01 12:26:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1556
////Problem Title: 
////Run result: Accept
////Run time:687MS
////Run memory:716KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1556.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月01日 星期六 11时42分47秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,i,c[100005];
int lowbit(int x)
{
	return (x&-x);
}
void update(int x,int d)
{
	while(x>0)
	{
		c[x]+=d;
		x-=lowbit(x);
	}
	return;
}
int sum(int x)
{
	int ret=0;
	while(x<=n)
	{
		ret+=c[x];
		x+=lowbit(x);
	}
	return ret;
}
int main()
{
	int a,b;
	while(scanf("%d",&n)!=EOF && n)
	{
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			update(b,1);
			update(a-1,-1);
		}
		printf("%d",sum(1));
		for(i=2;i<=n;i++)
		{
			printf(" %d",sum(i));
		}
		puts("");
	}
	return 0;
}