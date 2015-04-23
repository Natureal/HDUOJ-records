////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 14:28:59
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1869
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define INF 0x7FFFFFFF
int n,m;
int map[105][105],used[105],dis[105],con[205][2];
int Dijkstra(int s)
{
	int k;
	for(int i=0;i<n;i++)used[i]=0;

	used[s]=1;
	for(int i=0;i<n;i++)dis[i]=map[s][i];
	dis[s]=0;

	for(int i=0;i<n-1;i++)
	{
		int tmin=INF;
		for(int j=0;j<n;j++)
		{
			if(!used[j]&&tmin>dis[j]&&dis[j]!=INF)
			{
				tmin=dis[j];
				k=j;
			}
		}
		used[k]=1;
		for(int j=0;j<n;j++)
		{
			if(dis[k]+map[k][j]<dis[j] && map[k][j]!=INF)
			{
				dis[j]=dis[k]+map[k][j];
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(dis[i]>7)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int a,b,flag;
 	while(scanf("%d%d",&n,&m)!=EOF)
	{
		flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				map[i][j]=INF;
			}
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			if(a!=b)
			{
			   map[a][b]=map[b][a]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(Dijkstra(i)==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}