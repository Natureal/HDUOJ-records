////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-14 22:36:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3790
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:8156KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxint 1000000
int n,m,a,b,d,p,s,t;;
int used[1005],map1[1005][1005],map2[1005][1005],dis1[1005],dis2[1005];
void Dijkstra()
{
	int k;
	used[s]=1;
	for(int i=1;i<=n;i++)
	{
		dis1[i]=map1[s][i];
		dis2[i]=map2[s][i];
	}
	dis1[s]=dis2[s]=0;
	for(int i=1;i<n;i++)
	{
		int tmin=maxint;
		for(int j=1;j<=n;j++)
		{
			if(!used[j] && tmin>dis1[j])
			{
				tmin=dis1[j];
				k=j;
			}
		}
		used[k]=1;
		for(int j=1;j<=n;j++)
		{
			if(dis1[k]+map1[k][j]<dis1[j])
			{
				dis1[j]=dis1[k]+map1[k][j];
				dis2[j]=dis2[k]+map2[k][j];
			}
			else if(dis1[k]+map1[k][j]==dis1[j])
			{
				if(dis2[k]+map2[k][j]<dis2[j])
				{
					dis1[j]=dis1[k]+map1[k][j];
				    dis2[j]=dis2[k]+map2[k][j];
				}
			}
		}
	}
	printf("%d %d\n",dis1[t],dis2[t]);
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF && m||n)
	{
		memset(used,0,sizeof(used));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				map1[i][j]=maxint;
				map2[i][j]=maxint;
			}
		}
		while(m--)
		{
			scanf("%d%d%d%d",&a,&b,&d,&p);
			if(map1[a][b]>=d)
			{
			   map1[a][b]=map1[b][a]=d;
			   map2[a][b]=map2[b][a]=p;
			}
			else if(map1[a][b]==d)
			{
				map2[a][b]=map2[b][a]=map2[a][b]<p?map2[a][b]:p;
			}
		}
		scanf("%d%d",&s,&t);
		Dijkstra();
	}
	return 0;
}