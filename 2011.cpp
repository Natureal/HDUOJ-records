////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-14 23:53:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2011
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int m,a[100],i,j;
	double sum,b[100];
	while(scanf("%d",&m)!=EOF)
	{
		for(i=0;i<m;i++)
		{
			scanf("%d",&a[i]);
			for(j=1,sum=0;j<=a[i];j++)
			{
				if(j%2!=0)
				    sum+=1.0/(double)j;
				else
					sum-=1.0/(double)j;
			}
			b[i]=sum;
		}
		for(i=0;i<m;i++)
		{
			printf("%.2lf\n",b[i]);
		}
	}
	return 0;
}