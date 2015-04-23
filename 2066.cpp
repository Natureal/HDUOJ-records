////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 12:23:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:4224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define NUM 1005
#define INF 1000000
int t,s,d;
int map[NUM][NUM],used[NUM],dis[NUM],like[NUM];
void Dijkstra()
{
	int k,min=INF;
	used[0]=1;
	for(int i=0;i<=NUM;i++)dis[i]=map[0][i];
	for(int i=1;i<NUM;i++)
	{
		int tmin=INF;
		for(int j=1;j<=NUM;j++)
		{
			if(!used[j]&&tmin>dis[j])
			{
				tmin=dis[j];
				k=j;
			}
		}
		used[k]=1;
		for(int j=1;j<=NUM;j++)
		{
			if(dis[k]+map[k][j]<dis[j])
			{
				dis[j]=dis[k]+map[k][j];
			}
		}
	}
	for(int i=0;i<d;i++)
	{
		if(min>dis[like[i]])
		{
			min=dis[like[i]];
		}
	}
	printf("%d\n",min);
	return;
}
int main()
{
	int a,b,near,time,n,to;
	while(scanf("%d%d%d",&t,&s,&d)!=EOF)
	{
		for(int i=0;i<NUM;i++)
		{
			for(int j=0;j<NUM;j++)
			{
				map[i][j]=map[j][i]=INF;
			}
			used[i]=0;
		}
		while(t--)
		{
			scanf("%d%d%d",&a,&b,&time);
			if(map[a][b]>time)
			{
				map[a][b]=map[b][a]=time;
			}
		}
		while(s--)
		{
			scanf("%d",&near);
			map[0][near]=0;
		}
		n=0;
		for(int i=0;i<d;i++)
		{
			scanf("%d",&to);
			like[n++]=to;
		}
		Dijkstra();
	}
	return 0;
}