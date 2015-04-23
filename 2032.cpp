////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-10 11:12:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2032
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define N 30
#define M 100
int main()
{
	int i,j,k,l,m,a[M],b[N][N];
	for(l=0;l<M;l++)
	{
		scanf("%d",&a[l]);
		if(getchar() == '\n') break;
	}
	for(i=0;i<=l;i++)
	{
		for(j=0;j<a[i];j++)
		{
			b[j][0] = b[j][j] = 1;
		}
		for(j=2;j<a[i];j++)
		{
			for(k=1;k<j;k++)
			{
				b[j][k] = b[j-1][k] + b[j-1][k-1];
			}
		}
		for(m=0;m<a[i];m++)
		{
			for(k=0;k<m;k++)
			{
				printf("%-d ",b[m][k]);
			}
			printf("%-d\n",b[m][m]);
		}
		printf("\n");
	}
	return 0;
}