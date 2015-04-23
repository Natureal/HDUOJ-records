////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-16 22:08:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:640KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define INF 1000000
int n,m;
int map[1005][1005],dis[1005],used[1005];

void Dijkstra()
{
	int k;
	used[1]=1;
	for(int i=1;i<=n;i++) dis[i]=map[1][i];
	for(int i=1;i<n;i++)
	{
		int tmin=INF;
		for(int j=1;j<=n;j++)
		{
			if(!used[j] && tmin>dis[j])
			{
				tmin=dis[j];
				k=j;
			}
		}
		used[k]=1;
		for(int j=1;j<=n;j++)
		{
			if(dis[k]+map[k][j]<dis[j])
			{
				dis[j]=dis[k]+map[k][j];
			}
		}
	}
	printf("%d\n",dis[n]);
	return;
}
int main()
{
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF && n||m)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				map[i][j]=INF;
			}
			used[i]=0;
		}
		while(m--)
		{
			scanf("%d%d%d",&a,&b,&c);
			map[a][b]=c;
			map[b][a]=c;
		}
		Dijkstra();
	}
	return 0;
}