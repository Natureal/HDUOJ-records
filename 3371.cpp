////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-20 21:52:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3371
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:1236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define INF 10000000
int n,m,k,G[505][505],lowcost[505],closest[505];
void prim()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		lowcost[i]=G[1][i];
		closest[i]=0;
	}
	closest[1]=1;
	int sum=0;
	for(i=1;i<=n-1;i++)
	{
		int min=INF;
		for(j=1;j<=n;j++)
		{
			if(!closest[j]&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
			}
		}
		if(min==INF)break;
		closest[k]=1;
		sum+=min;
		for(j=1;j<=n;j++)
		{
			if(!closest[j]&&lowcost[j]>G[k][j])
			{
				lowcost[j]=G[k][j];
			}
		}
	}
	if(i<=n-1)
		printf("-1\n");
	else
		printf("%d\n",sum);
}
int main()
{
	int t,p,q,c,n1,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				G[i][j]=INF;
			}
		}
		while(m--)
		{
			scanf("%d%d%d",&p,&q,&c);
			if(G[p][q]>c)
			{
				G[p][q]=G[q][p]=c;
			}
		}
		while(k--)
		{
			scanf("%d%d",&n1,&a);
			for(int i=1;i<=n1-1;i++)
			{
				scanf("%d",&b);
				G[a][b]=G[b][a]=0;
			}
		}
		prim();
	}
	return 0;
}