////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-08 22:14:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1518
////Problem Title: 
////Run result: Accept
////Run time:2875MS
////Run memory:320KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1518.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月08日 星期六 21时38分05秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int t,n,len[21],vis[21],sum,tar,flag;
bool dfs(int pos,int now,int num)
{
	if(num==3)
	{
		return true;
	}
	for(int i=pos;!flag&&i<=n;i++)
	{
		if(!vis[i])
		{
			if(now+len[i]==tar)
			{
				vis[i]=1;
				if(dfs(0,0,num+1))
					return true;
				vis[i]=0;
			}
			if(now+len[i]<tar)
			{
				vis[i]=1;
				if(dfs(i,now+len[i],num))
					return true;
				vis[i]=0;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&len[i]);
			sum+=len[i];
		}
		tar=sum/4;
		if(sum%4!=0||tar<len[1])
		{
			printf("no\n");
			continue;
		}
		flag=0;
		if(dfs(0,0,0))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}