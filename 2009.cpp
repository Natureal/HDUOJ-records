////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-14 23:40:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2009
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	double n,i,sum;
	int m;
	while(scanf("%lf %d",&n,&m)!=EOF)
	{
		i=sum=n;
		m--;
		while(m--)
		{
			i=sqrt(i);
			sum+=i;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}