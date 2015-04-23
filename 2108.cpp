////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-10 23:35:45
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int x[10001][2],n,i,count,x1,y1,x2,y2;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&x[i][0],&x[i][1]);
		}
		x[n][0]=x[0][0];
		x[n][1]=x[0][1];
		x[n+1][0]=x[1][0];
		x[n+1][1]=x[1][1];
		count=1;
		for(i=0;i<n;i++)
		{
			x1=x[i+1][0]-x[i][0];
			x2=x[i+2][0]-x[i+1][0];
			y1=x[i+1][1]-x[i][1];
			y2=x[i+2][1]-x[i+1][1];
			if((x1*y2-x2*y1)<0)
			{
				count=0;
				break;
			}
		}
		if(count)
			printf("convex\n");
		else
			printf("concave\n");
	}
	return 0;
}