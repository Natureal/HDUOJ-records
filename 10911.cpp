////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-07 00:51:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1091
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b;
	
	while(scanf("%d %d",&a,&b)!=EOF) 
	{
		if(0==a && 0==b)
		{
			return 0;
		}
		printf("%d\n",a+b);
	}
	return 0;
}