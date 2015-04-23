////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-16 17:46:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1869
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define INF 1000000
int n,m;
int map[105][105];
void Floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(map[i][j]>map[i][k]+map[k][j]&&map[i][k]!=INF&&map[k][j]!=INF)
				{
					map[i][j]=map[i][k]+map[k][j];
				}
			}
		}
	}
}
int judge()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[i][j]>7)
				return 0;
		}
	}
	return 1;
}
int main()
{
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				map[i][j]=INF;
			}
		}
		for(int i=0;i<n;i++)
		{
			map[i][i]=0;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=map[b][a]=1;
		}
		Floyd();
		if(judge())
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}