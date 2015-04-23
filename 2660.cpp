////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-06 21:42:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2660
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:372KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2660.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月06日 星期四 21时15分03秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int stone[25][2],n,k,maxv,maxw,vis[25];
void dfs(int sum,int pos,int we,int num)
{
	if(num==k||we==maxw)
	{
		if(maxv<sum)
			maxv=sum;
		return;
	}
	for(int i=pos;i<=n;i++)
	{
		if(!vis[i]&&we+stone[i][1]<=maxw&&num+1<=k)
		{
			vis[i]=1;
			dfs(sum+stone[i][0],i+1,we+stone[i][1],num+1);
			vis[i]=0;//important!
		}
	}
	return;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		maxv=0;
		for(int i=1;i<=n;i++)
		{
			cin>>stone[i][0]>>stone[i][1];
			vis[i]=0;
		}
		cin>>maxw;
		dfs(0,0,0,0);
		cout<<maxv<<endl;
	}
	return 0;
}