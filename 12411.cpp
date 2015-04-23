////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-05 23:52:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1241
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:396KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1241.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月05日 星期三 22时38分03秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,m,map[105][105];
void dfs(int x,int y)
{
	if(!map[x][y]) return;
	map[x][y]=0;
	dfs(x-1,y-1);dfs(x-1,y);dfs(x-1,y+1);
	dfs(x,y-1);				dfs(x,y+1);
	dfs(x+1,y-1);dfs(x+1,y);dfs(x+1,y+1);
}
int main()
{
	char temp[105];
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m==0&&n==0)break;
	//	memset(vis,0,sizeof(vis));
		memset(map,0,sizeof(map));
		for(int i=1;i<=m;i++)
		{
			scanf("%s",temp);
			for(int j=1;j<=n;j++)
			{
				if(temp[j-1]=='*')
					map[i][j]=0;
				else if(temp[j-1]=='@')
					map[i][j]=1;
			}
		}
		int count=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(map[i][j])
				{
					count++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}