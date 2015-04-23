////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-08 21:11:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1175
////Problem Title: 
////Run result: Accept
////Run time:8125MS
////Run memory:5192KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1175.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月08日 星期六 17时16分43秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
const int MAX=1002;
int map[MAX][MAX];
int n,m,q,x1,y1,x2,y2;
bool flag=false,vis[MAX][MAX];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y,int cnt,int d)
{
	if(flag||cnt>2||vis[x][y])
		return;
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int a,b,t;
		a = x + dir[i][0];
		b = y + dir[i][1];
		if(d!=i) t = cnt + 1;
		else t = cnt;
		if(a==x2&&b==y2&&t<=2)
		{
			flag=true;
			return;
		}
	//	printf("%d%d%d%d\n",x,y,a,b);
		if(!map[a][b]&&!vis[a][b])
		{
			dfs(a,b,t,i);
		}
	}
	vis[x][y]=false;
	return;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		memset(map,-1,sizeof(map));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			flag=false;
			memset(vis,false,sizeof(vis));
			if(map[x1][y1]!=map[x2][y2] || map[x1][y1]==0 || map[x2][y2]==0)
			{
				printf("NO\n");
				continue;
			}
			dfs(x1,y1,-1,-1);
			if(flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}