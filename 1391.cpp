////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-26 21:47:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1391
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&a,&b);
		if(a==b || a-2==b)
		{
			if(a%2)
			{
				printf("%d\n",a+b-1);
			}
			else
			{
				printf("%d\n",a+b);
			}
		}
		else
		{
			printf("No Number\n");
		}
	}
	return 0;
}