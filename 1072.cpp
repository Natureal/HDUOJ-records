////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-08 17:13:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:388KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1072.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月08日 星期六 16时37分36秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
int t,n,m,map[10][10];
int dir[4][2]={-1,0,1,0,0,-1,0,1};
struct node
{
	int x,y,use,remain;
}st;
void bfs()
{
	queue<node> q;
	q.push(st);
	struct node p1,p2;
	while(!q.empty())
	{
		p1=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			p2.use=p1.use+1;
			p2.remain=p1.remain-1;
			p2.x=p1.x+dir[i][0];
			p2.y=p1.y+dir[i][1];
			if(p2.x>0&&p2.x<=n&&p2.y>0&&p2.y<=m&&map[p2.x][p2.y]!=0&&p2.remain>0)
			{
				if(map[p2.x][p2.y]==3)
				{
					printf("%d\n",p2.use);
					return;
				}
				if(map[p2.x][p2.y]==4)
				{
					p2.remain=6;
					map[p2.x][p2.y]=1;
				}
				q.push(p2);
			}
		}
	}
	printf("-1\n");
	return;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
				{
					st.x=i;
					st.y=j;
					st.use=0;
					st.remain=6;
				}
			}
		}
		bfs();
	}
	return 0;
}
