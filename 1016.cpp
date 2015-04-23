////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-07 18:17:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1016
////Problem Title: 
////Run result: Accept
////Run time:937MS
////Run memory:384KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1016.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月07日 星期五 17时41分44秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int vis[21],arr[21],n;
bool check(int x)
{
	int i;
	for(i=2;i<x;i++)
	{
		if(0==x%i)
			return 0;
	}
	return 1;
}
void dfs(int pos,int arrpos)
{
	arr[arrpos]=pos;
	vis[pos]=1;
	if(arrpos==n)
	{
		if(check(arr[n]+arr[1]))
		{
			cout<<"1";
			for(int j=2;j<=n;j++)
			{
				cout<<" "<<arr[j];
			}
			cout<<endl;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&check(arr[arrpos]+i))
		{
			dfs(i,arrpos+1);
			vis[i]=0;
		}
	}
	return;
}
int main()
{
	int t=0;
	while(cin>>n)
	{
		t++;
		memset(vis,0,sizeof(vis));
		memset(arr,0,sizeof(arr));
		cout<<"Case "<<t<<":"<<endl;
		dfs(1,1);
		cout<<endl;
	}
	return 0;
}