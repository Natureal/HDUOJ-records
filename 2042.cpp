////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 00:06:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2042
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,i,k;
	scanf("%d",&n);
	while(n--)
	{
		k=3;
		scanf("%d",&a);
		for(i=0;i<a;i++)
		{
			k=2*(k-1);
		}
		printf("%d\n",k);
	}
	return 0;
}