////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-09 00:00:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2012
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int check_prime(int x);
int function(int y);

int main()
{
	int i,a,b,count;

	while(2 == scanf("%d %d",&a,&b))
	{
		if( 0 == a && 0 == b)
		{
			return 0;
		}
		for(i = a,count = 0;i <= b;i++)
		{
			count += function(i); 
		}
		if(count == b - a + 1)
		{
			printf("OK\n");
		}
		else
		{
			printf("Sorry\n");
		}
	}
	return 0;
}

int function(int x)
{
	int sum;
	sum = x*x + x + 41;
	if(check_prime(sum))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int check_prime(int y)
{
	int i,k;
	k = sqrt(1.0*y);
	for(i=2;i<=k;i++)
	{
		if( 0 == y % i)
		{
			break;
		}
	}
	if(i > k)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
