////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-13 16:26:43
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1012
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
double calculate(int x);
int main()
{
	int n;
	printf("n e\n");
	printf("- -----------\n");
	for(n=0;n<=9;n++)
	{
		if(n==0||n==1)
		{
			printf("%d %.lf\n",n,calculate(n));
		}
		else if(n==2)
		{
			printf("%d %.1lf\n",n,calculate(n));
		}
		else
		{
			printf("%d %.9lf\n",n,calculate(n));
		}
	}
	return 0;
}

double calculate(int x)
{
	int i,j,k;
	double e=1;
	if(x==0)
	{
		return 1;
	}
	for(i=1;i<=x;i++)
	{
		for(j=2,k=1;j<=i;j++)
		{
			k=k*j;
		}
		e+=(1/(double)k);
	}
	return e;
}