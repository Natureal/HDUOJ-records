////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-12 23:47:57
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2092
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	double A,B,der;
	while(scanf("%lf%lf",&A,&B)!=EOF && A||B)
	{
		der=sqrt(A*A-4*B)/2+A/2;
        printf(((int) der==der)?"Yes\n":"No\n");

	}
	return 0;
}