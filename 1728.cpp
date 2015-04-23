////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-25 21:31:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1728
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:392KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1728.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月25日 星期二 20时52分52秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
const int MAX=110;
char map[MAX][MAX];
int vis[MAX][MAX];
int m,n,step,sx,sy,ex,ey,flag;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

struct NODE
{
	int x;
	int y;
};
typedef struct NODE node;
void BFS()
{
	int k,turns;
	node q,p;
	queue<node>Q;
	p.x=sx;
	p.y=sy;
	Q.push(p);
	while(!Q.empty())
	{
		q=Q.front();
		Q.pop();
		turns=vis[q.x][q.y]+1;
		for(k=0;k<4;k++)
		{
			p.x=q.x+dir[k][0];
			p.y=q.y+dir[k][1];
			while(p.x>=0 && p.x<m && p.y>=0 && p.y<n && map[p.x][p.y]=='.')
			{
				if(vis[p.x][p.y]==-1)
				{
					if(p.x==ex&&p.y==ey&&turns<=step)
					{
						flag=1;
						return;
					}
					vis[p.x][p.y]=turns;
					Q.push(p);
				}
				p.x+=dir[k][0];
				p.y+=dir[k][1];
			}
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
		cin>>m>>n;

		for(int i=0;i<m;i++)cin>>map[i];

		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				vis[i][j]=-1;
		cin>>step>>sy>>sx>>ey>>ex;
		sx--;
		sy--;
		ey--;
		ex--;
		if(sx==ex&&sy==ey)
		{
			cout<<"yes"<<endl;
			continue;
		}
		flag=0;
		BFS();
		if(flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}