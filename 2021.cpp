////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-09 18:45:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2021
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>

#define N 100

int main()
{
	int n,a[N],i,sum;
	
	while((scanf("%d",&n)!=EOF) && n )
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);

			sum = sum +a[i]/100+a[i]%100/50+a[i]%100%50/10+a[i]%100%50%10/5+a[i]%100%50%10%5/2+a[i]%100%50%10%5%2;
		}
		printf("%d\n",sum);
	}
	return 0;
}