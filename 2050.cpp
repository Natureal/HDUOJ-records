////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 15:26:08
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include <stdio.h>
_int64 div(int x)
{
	if(1==x)
		return 2;
	else
		return div(x-1)+4*(x-1)+1;
}
int main()
{
	int c,n;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		printf("%d\n",div(n));
	}
	return 0;
}