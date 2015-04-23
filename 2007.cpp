////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-08 23:22:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2007
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b,i;
	int sum1,sum2;
	while(2==scanf("%d %d",&a,&b))
	{
		i=a+b;
		a=a<b?a:b;
		b=i-a;
		sum1=sum2=0;
		for(i=a;i<=b;i++)
		{
			if(0 == i%2)
			{
				sum1+= i*i;
			}
			else
			{
				sum2+= i*i*i;
			}
		}
		printf("%d %d\n",sum1,sum2);
	}
	return 0;
}