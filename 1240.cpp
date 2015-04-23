////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-26 17:18:28
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1240
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1240.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月26日 星期三 16时02分36秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
int n,sx,sy,sz,ex,ey,ez,countk;
char map[10][10][10];
int dir[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
struct Node
{
	int x,y,z;
	int count;
};
typedef struct Node node;
bool judge(int x,int y,int z)
{
	if(x<0||x>=n||y<0||y>=n||z<0||z>=n)return false;//越界
	if(map[x][y][z])return false;//已经访问或者是barrier
	return true;
}
void BFS()
{
	int i;
	queue<node> q;
	node pos,next;

	pos.x=sx;
	pos.y=sy;
	pos.z=sz;
	pos.count=0;
	map[pos.x][pos.y][pos.z]=1;

	while(!q.empty())
		q.pop();//清空队列
	q.push(pos);//将起点压入队列
	while(!q.empty())
	{
		pos=q.front();
		q.pop();//将头元素取出并从队列中去掉～
		if(pos.x==ex&&pos.y==ey&&pos.z==ez)
		{
			countk=pos.count;
			return;
		}
		for(i=0;i<6;i++)
		{
			next.x=pos.x+dir[i][0];
			next.y=pos.y+dir[i][1];
			next.z=pos.z+dir[i][2];

			if(judge(next.x,next.y,next.z))
			{
				next.count=pos.count+1;
				map[next.x][next.y][next.z]=1;//防止重复访问
				q.push(next);
			}
		}
	}
	return;
}
int main()
{
	int m,i,j;
	char str1[6],str2[4];
	while(cin>>str1>>n)
	{
		for(m=0;m<n;m++)
		{
			for(i=0;i<n;i++)
			{
				cin>>map[m][i];
				for(j=0;j<n;j++)
				{
					if(map[m][i][j]=='O')
						map[m][i][j]=0;
					else if(map[m][i][j]=='X')
						map[m][i][j]=1;
				}
			}
		}
		cin>>sz>>sy>>sx>>ez>>ey>>ex;
		cin>>str2;
		countk=-1;
		BFS();
		if(countk==-1)
			cout<<"NO ROUTE"<<endl;
		else
			cout<<n<<" "<<countk<<endl;
	}
	return 0;
}