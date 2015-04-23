////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-03 23:44:29
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1018
////Problem Title: 
////Run result: Accept
////Run time:406MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int t,i,n;
	double re;
	scanf("%d",&t);
	while(t--)
	{
		re=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			re+=(log10(1.0*i));
		}
		printf("%d\n",(int)re+1);
	}
	return 0;
}