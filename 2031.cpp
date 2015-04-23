////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-10 00:41:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2031
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define N 100
int main()
{
	int n,r,quotients,remainder,i,j,sign;
	char a[N]={0};
	char b[17]={"0123456789ABCDEF"};
	while(scanf("%d %d",&n,&r) == 2)
	{
		sign = 0;
		if( n < 0) 
	    {
			n = -n;
			sign ++;
		}
		quotients = remainder = n;
		for(i=0;;i++)
		{
			if( quotients == r)
			{
				a[i] = b[1];
				break;
			}
			if( quotients/r && i!=0)
			{
			quotients = quotients/r;
			remainder = quotients%r;
			a[i] = b[remainder];
			}
			else if( quotients/r && i == 0)
			{
			remainder = quotients%r;
			a[i] = b[remainder];
			}
			else if( 0 == quotients/r && i == 0 && n)
			{
			  a[i] = b[remainder];
			  break;
			}
			else
			{
			break;
			}
		}
		for(j=i-1;j>=0;j--)
		{
			if( sign && j == i-1)
			printf("-%c",a[j]);
			else
			printf("%c",a[j]);
		}
		printf("\n");
	}
	return 0;
}