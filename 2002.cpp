////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-14 23:06:50
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2002
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define PI 3.1415927
int main()
{
	double r,v;
	while(scanf("%lf",&r)!=EOF)
	{
		v=4*PI*r*r*r/3;
		printf("%.3lf\n",v);
	}
	return 0;
}