////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-05 22:22:04
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1010
////Problem Title: 
////Run result: Accept
////Run time:640MS
////Run memory:256KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1010.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月05日 星期三 21时44分48秒
 ************************************************************************/

#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<iostream>
using namespace std;
int n,m,t,sx,sy,ex,ey,map[10][10],flag;
int dir[4][2]={0,1,0,-1,-1,0,1,0};
void dfs(int x,int y,int t)
{
	if(flag) return;
	if(t<abs(ex-x)+abs(ey-y)||(t-abs(ey-y)+abs(ex-x))%2) return;//时间不足，或者奇偶判断显示是错误的
	if(t==0)
	{
		if(x==ex&&y==ey)
			flag=1;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(nx>0&&nx<=n&&ny>0&&ny<=m&&!map[nx][ny])
		{
			map[nx][ny]=1;
			dfs(nx,ny,t-1);
			map[nx][ny]=0;//重新恢复，很重要！
		}
	}
	return;
}
int main()
{
	char temp[10];
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		if(n==0&&m==0&&t==0) break;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",temp);
			for(int j=1;j<=m;j++)
			{
				if(temp[j-1]=='S')
				{
					sx=i,sy=j;
					map[i][j]=1;
				}
					//sx=i,sy=j;
				else if(temp[j-1]=='D')
				{
					ex=i,ey=j;
					map[i][j]=0;
				}
				else if(temp[j-1]=='.')
					map[i][j]=0;
				else if(temp[j-1]=='X')
					map[i][j]=1;
			}
		}
		flag=0;
		dfs(sx,sy,t);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}