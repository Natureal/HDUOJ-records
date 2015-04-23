////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-20 21:15:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:764KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define MAXN 1005 
#define INF 0x7fffffff
double G [MAXN][MAXN],lowcost[MAXN],x[1005],y[1005];
int n,closest[MAXN];
double cal(double x1,double y1,double x2,double y2)
{
	return sqrt(1.0*(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
void prim()
{
	int i,j;
	for(i=0;i<n;i++)
	{
		lowcost[i]=G[0][i];
		closest[i]=0;
	}
	closest[0]=1;
	int e=0,k;
	double sum=0.0;
	for(i=0;i<n-1;i++)
	{
		double min=INF;
		for(j=0;j<n;j++)
		{
			if(!closest[j]&&lowcost[j]<min)
			{
				min=lowcost[j];
				k=j;
			}
		}
		if(min==INF)break;
		sum+=min;
		closest[k]=1;
		for(j=0;j<n;j++)
		{
			if(!closest[j]&&G[k][j]<lowcost[j])
				lowcost[j]=G[k][j];
		}
	}
	if(i<n-1)
	{
		printf("oh!\n");
	}
	else printf("%.1lf\n",sum*100);
	//for(i=0;i<n-1;i++)
	//{
	//	double min=INF;
	//	int miedge=-1;
	//	for(int j=0;j<n;j++)
	//	{
	//		if(!closest[j])
	//		{
	//			double temp=G[e][j];
	//			if(temp<lowcost[j])
	//			{
	//				lowcost[j]=temp;
	//				closest[j]=e;
	//			}
	//			if(lowcost[j]<min)
	//			{
	//				min=lowcost[miedge=j];
	//			}
	//		}
	//	}
	//	if(min>=INF)break;
	//	sum+=min;
	//	closest[e=miedge]=1;
	//}
	//if(i>=n-1)
	//{
	//   printf("%.1lf\n",sum*100);
	//}
	//else printf("oh!\n");
	//return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&x[i],&y[i]);
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				G[i][j]=INF;
		for(int i=0;i<n;i++)
		{
			for(int j=i;j<n;j++)
			{
				double temp;
				temp=cal(x[i],y[i],x[j],y[j]);
				if(temp>=10.000000&&temp<=1000.000001)
				{
			    	G[i][j]=G[j][i]=temp;
				}
			}
		}
		prim();
	}
	return 0;
}