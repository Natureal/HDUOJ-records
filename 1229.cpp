////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 23:42:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1229
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,j,a,b,k;
	while(scanf("%d %d %d",&a,&b,&k) && (a||b))
	{
		i=1;
		for(j=0;j<k;j++)
		{
			i*=10;
		}
		if(a%i==b%i)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n",a+b);
		}
	}
	return 0;
}