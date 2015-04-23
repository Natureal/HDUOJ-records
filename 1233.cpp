////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-15 23:12:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1233
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:296KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define max_vertexes 100
#define infinity 1000000
typedef int Graph[max_vertexes][max_vertexes];
void prim(Graph G,int vcount,int father[])
{
	int i,j,k,sum=0;
	int lowcost[max_vertexes];
	int closeset[max_vertexes],used[max_vertexes];
	int min;
	for(i=0;i<vcount;i++)
	{
		lowcost[i]=G[0][i];
		closeset[i]=0;//记录依附点
		used[i]=0;
		father[i]=-1;
	}
	used[0]=1;
	for(i=0;i<=vcount-1;i++)//重要循环部分
	{
		j=0;
		min=infinity;
		for(k=1;k<vcount;k++)
		{
			if(!used[k] && (lowcost[k]<min))
			{
				min=lowcost[k];
				j=k;
			}
		}
		sum+=min;
		father[j]=closeset[j];
		used[j]=1;
		for(k=1;k<vcount;k++)//更新j的最小权值
		{
			if(!used[k] && (G[j][k]<lowcost[k]))
			{
				 lowcost[k]=G[j][k];
				 closeset[k]=j;
			}
		}
	}
	printf("%d\n",sum-infinity);
	return;
}
int main()
{
	int n,i,j,r,l,s;
	Graph G;
	int father[100];
	while(scanf("%d",&n)!=EOF && n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				G[i][j]=infinity;
			}
		}
		int k=n*(n-1)/2;
		for(i=0;i<k;i++)
		{
			scanf("%d %d %d",&r,&l,&s);
			G[r-1][l-1]=G[l-1][r-1]=s;
		}
		prim(G,n,father);
	}
	return 0;
}