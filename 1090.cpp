////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-07 00:46:32
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b,n;
	
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d %d",&a,&b);
			printf("%d\n",a+b);
		}
	}
	return 0;
}