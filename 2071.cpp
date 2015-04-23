////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-19 00:40:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2071
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int c,n;
	float max,k;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		max=0;
		while(n--)
		{
			scanf("%f",&k);
			max=max>k?max:k;
		}
		printf("%.2f\n",max);
	}
	return 0;
}