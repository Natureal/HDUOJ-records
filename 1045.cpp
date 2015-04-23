////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-08 16:12:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:320KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1045.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月08日 星期六 15时47分00秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,map[5][5],count;
int judge(int k)
{
	int x=k/n;
	int y=k%n;
	for(int i=y;i>=0;i--)
	{
		if(map[x][i]==2)
			return 0;
		if(map[x][i]==1)
			break;
	}
	for(int i=x;i>=0;i--)
	{
		if(map[i][y]==2)
			return 0;
		if(map[i][y]==1)
			break;
	}
	return 1;
}
void dfs(int k,int c)
{
	int x=k/n;
	int y=k%n;
	if(k==n*n)
	{
		if(c>count)
			count=c;
		return;
	}
	if(map[x][y]==0 && judge(k))
	{
		map[x][y]=2;
		dfs(k+1,c+1);
		map[x][y]=0;
	}
	dfs(k+1,c);//没放
	return;
}
int main()
{
	char temp[5];
	while(cin>>n,n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>temp;
			for(int j=0;j<n;j++)
			{
				if(temp[j]=='.')
					map[i][j]=0;
				else if(temp[j]=='X')
					map[i][j]=1;
			}
		}
		count=0;
		dfs(0,0);
		cout<<count<<endl;
	}
	return 0;
}