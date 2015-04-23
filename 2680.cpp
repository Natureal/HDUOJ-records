////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-17 15:39:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2680
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:4176KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define INF 1000000
int map[1005][1005],used[1005],dis[1005];
int n,m,s,w;
void Dijkstra()
{
	int k;
	for(int i=0;i<=n;i++)used[i]=0;
	used[0]=1;
	for(int i=0;i<=n;i++)dis[i]=map[0][i];
	for(int i=0;i<n;i++)
	{
		int tmin=INF;
		for(int j=0;j<=n;j++)
		{
			if(!used[j]&&tmin>dis[j])
			{
				tmin=dis[j];
				k=j;
			}
		}
		if(tmin==INF)break;
		//киЁз
		used[k]=1;
		for(int j=0;j<=n;j++)
		{
			if(!used[j]&&dis[k]+map[k][j]<dis[j])
			{
				dis[j]=dis[k]+map[k][j];
			}
		}
	}
	if(dis[s]!=INF)printf("%d\n",dis[s]);
	else printf("-1\n");
	return;
}
int main()
{
	int p,q,t,be;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF)
	{
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				map[i][j]=INF;
		while(m--)
		{
			scanf("%d%d%d",&p,&q,&t);
			if(map[p][q]>t)
				map[p][q]=t;
		}
		scanf("%d",&w);
		while(w--)
		{
			scanf("%d",&be);
			map[0][be]=0;
		}
		Dijkstra();
	}
	return 0;
}