////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 21:49:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2036
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int n,i;
	double s,a[100][2];
	while(scanf("%d",&n)!=EOF && n)
	{
		s=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf",&a[i][0],&a[i][1]);
		}
		for(i=0;i<n-1;i++)
		{
			s=s+(a[i][0]*a[i+1][1]-a[i+1][0]*a[i][1])/2;
		}
		s=s+(a[n-1][0]*a[0][1]-a[0][0]*a[n-1][1])/2;
		printf("%.1lf\n",fabs(s));
	}
	return 0;
}