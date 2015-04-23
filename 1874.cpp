////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 11:17:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:348KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define INF 1000000
int used[205],map[205][205],dis[205];
int s,e,n,m;
void Dijkstra()
{
	int k;
	used[s]=1;
	for(int i=1;i<=n;i++)dis[i]=map[s][i];
	for(int i=1;i<n;i++)
	{
		int tmin=INF;
		for(int j=1;j<=n;j++)
		{
			if(!used[j]&&tmin>dis[j])
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
	if(dis[e]==INF)printf("-1\n");
	else printf("%d\n",dis[e]);
	return;
}
int main()
{
	int a,b,x;
	while(scanf("%d%d",&n,&m)!=EOF)
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
			scanf("%d%d%d",&a,&b,&x);
			if(map[a+1][b+1]>x)
			{
			    map[a+1][b+1]=map[b+1][a+1]=x;
			}
		}
		scanf("%d%d",&s,&e);
		s++;
		e++;
		if(s==e)printf("0\n");
		else Dijkstra();
	}
	return 0;
}