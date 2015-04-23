////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-20 00:09:08
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2101
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int  a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		a=a+b;
		a=a%86;
		if(a==0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}