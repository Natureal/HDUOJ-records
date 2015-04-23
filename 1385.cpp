////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-17 16:56:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1385
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:292KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define INF 0x7fffffff
int map[105][105],path[105][105],tax[105];
int n;
void Floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(map[i][k]!=INF&&map[k][j]!=INF)
				{
					int temp=map[i][k]+map[k][j]+tax[k];
					if(map[i][j]>temp)
					{
						map[i][j]=temp;
						path[i][j]=path[i][k];
					}
					else if(map[i][j]==temp && path[i][j]>path[i][k])
					{
						path[i][j]=path[i][k];
					}
				}
			}
		}
	}
	return;
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			map[i][j]=INF;
			path[i][j]=j;
		}
		map[i][i]=0;
	}
	return;
}
int main()
{
	int a,b,u;
	while(scanf("%d",&n)!=EOF && n)
	{
		init();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==-1)
					map[i][j]=INF;
			}
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tax[i]);
		}
		Floyd();
		while(scanf("%d%d",&a,&b)!=EOF)
		{
			if(a==-1&&b==-1)break;
			u=a;
			printf("From %d to %d :\n",a,b);
			printf("Path: %d",a);
			while(u!=b)
			{
				printf("-->%d",path[u][b]);
				u=path[u][b];
			}
			puts("");
			printf("Total cost : %d\n\n",map[a][b]);
		}
	}
	return 0;
}