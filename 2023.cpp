////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-09 22:58:57
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2023
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define N 51
#define M 6
int main()
{
	int n,m,a[N][M]={0},i,j,count,sign,sum[N]={0},sum2[M]={0};
	double aver_person[N],aver_subject[M];
	while(scanf("%d %d",&n,&m)==2)
	{
		sign = 0;
		for(i=0;i<n;i++)
		{
			sum[i]=0;
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
				sum[i]+=a[i][j];
			}
			aver_person[i] = 1.0*sum[i]/m;
		}
		for(j=0;j<m;j++)
		{
			sum2[j]=0;
			for(i=0;i<n;i++)
			{
				sum2[j]+= a[i][j];
			}
			aver_subject[j] = 1.0*sum2[j]/n;
		}
		for(i=0;i<n;i++)
		{
			count = 0;
			for(j=0;j<m;j++)
			{
				count += (a[i][j] >= aver_subject[j]);
			}
			if( m == count)
				sign ++;
		}
		for(i=0;i<n-1;i++)
		{
			printf("%.2lf ",aver_person[i]);
		}
		printf("%.2lf\n",aver_person[n-1]);
		for(j=0;j<m-1;j++)
		{
			printf("%.2lf ",aver_subject[j]);
		}
		printf("%.2lf\n",aver_subject[m-1]);
		printf("%d\n\n",sign);
	}
	return 0;
}