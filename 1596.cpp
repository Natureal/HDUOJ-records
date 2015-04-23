////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-20 22:46:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1596
////Problem Title: 
////Run result: Accept
////Run time:1015MS
////Run memory:6700KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int used[1005],n,s,e;
double map[1005][1005],dis[1005];
void Dijkstra()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		dis[i]=map[s][i];
		used[i]=0;
	}
	used[s]=1;
	for(i=1;i<=n;i++)
	{
		double max=-1;
		for(j=1;j<=n;j++)
		{
			if(!used[j]&&max<dis[j])
			{
				max=dis[j];
				k=j;
			}
		}
		if(max==0)break;
		used[k]=1;
		for(j=1;j<=n;j++)
		{
			if(!used[j]&&dis[k]*map[k][j]>dis[j])
			{
				dis[j]=dis[k]*map[k][j];
			}
		}
	}
	if(i<=n)printf("What a pity!\n");
	else printf("%.3lf\n",dis[e]);
	return;
}
int main()
{
	int i,j,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<=n;i++)
	    	for(j=1;j<=n;j++)
	        	map[i][j]=0.0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%lf",&map[i][j]);
			}
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&s,&e);
			Dijkstra();
		}
	}
	return 0;
}