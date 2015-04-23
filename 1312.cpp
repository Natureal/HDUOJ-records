////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-06 21:01:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1312
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:364KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1312.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月06日 星期四 20时40分54秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int dir[4][2]={0,1,0,-1,-1,0,1,0};
int map[25][25],sx,sy;
void dfs(int x,int y)
{
	if(map[x][y]) return;
	map[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int nx=x+dir[i][0],ny=y+dir[i][1];
		dfs(nx,ny);
	}
	return;
}
int main()
{
	int n,m;
	char temp[25];
	while(cin>>m>>n)
	{
		if(n==0&&m==0) break;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
				map[i][j]=1;
		int countw=0;
		for(int i=1;i<=n;i++)
		{
			cin>>temp;
			for(int j=1;j<=m;j++)
			{
				if(temp[j-1]=='.')
				{
					map[i][j]=0;
					countw++;
				}
				else if(temp[j-1]=='#')
					map[i][j]=1;
				else if(temp[j-1]=='@')
				{
					map[i][j]=0;
					countw++;
					sx=i;
					sy=j;
				}
			}
		}
		dfs(sx,sy);
		int count=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(map[i][j]==0)
				{
					count++;
				}
		printf("%d\n",countw-count);
	}
	return 0;
}