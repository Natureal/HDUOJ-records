////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-19 23:58:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1098
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int k,a,i;
	while(scanf("%d",&k)!=EOF)
	{
		a=0;
		for(i=1;i<=65;i++)
		{
			if((18+k*i)%65==0)
			{
				a=i;
				break;
			}
		}
		if(a==0)
		{
			printf("no\n");
		}
		else
		{
			printf("%d\n",a);
		}
	}
	return 0;
}