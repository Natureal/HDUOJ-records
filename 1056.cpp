////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-13 19:45:47
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1056
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
double check(double x);
int main()
{
	double n,k;
    while(scanf("%lf",&n)!=EOF && n!=0.00)
	{
		k=check(n);
	    printf("%.lf card(s)\n",k);
	}
	return 0;
}

double check(double x)
{
	double sum=0,i;
	for(i=2;;i++)
	{
		sum=sum+1.0/i;
		if(sum>=x)
		{
			break;
		}
	}
	return (i-1);
}