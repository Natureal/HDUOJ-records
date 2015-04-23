////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-09 00:12:19
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2502
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int t;
	double n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&n);
		printf("%.0lf\n",pow(2.0,n-1)+(n-1)*pow(2.0,n-2));
	}
	return 0;
}