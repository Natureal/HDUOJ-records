////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-19 17:20:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1162
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:364KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 105
int n;;
int used[MAX];
double G[MAX][MAX],x[MAX],y[MAX],dist[MAX];
double cal(double x1,double y1,double x2,double y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
void prim(double G[MAX][MAX],int vcount)
{
	int i,j,k;
	double sum=0;
	double min;
	for(i=1;i<=vcount;i++)
	{
		dist[i]=G[1][i];
	}
	used[1]=1;
	for(i=2;i<=vcount;i++)
	{
		j=1;
		min=10000;
		for(k=1;k<=vcount;k++)
		{
			if(!used[k]&&dist[k]<min)
			{
				min=dist[k];
				j=k;
			}
		}
		sum+=min;
		used[j]=1;
		for(k=1;k<=vcount;k++)
		{
			if(!used[k]&&G[j][k]<dist[k])
			{
				dist[k]=G[j][k];
			}
		}
	}
	printf("%.2lf\n",sum);
	return;
}
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		//for(i=0;i<n;i++)
		//	for(j=0;j<n;j++)
		//		G[i][j]=INF;
		for(i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x[i],&y[i]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=i;j<=n;j++)
			{
				G[i][j]=G[j][i]=cal(x[i],y[i],x[j],y[j]);
			}
		}
		memset(used,0,sizeof(used));
		prim(G,n);
	}
	return 0;
}