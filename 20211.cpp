////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-09 18:52:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2021
////Problem Title: 
////Run result: Accept
////Run time:0MS
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
			//如果采用 a[i]/100 + (a[i]%100)/50 + (a[i]%50)/10 + (a[i]%10)/5 + (a[i]%5)/2 + a[i]%2 会发现当工资为偶数时，将不能计入1元面值的数量！！
		}
		printf("%d\n",sum);
	}
	return 0;
}