////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-20 23:14:10
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int m,n,a,b,r=1;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		a=m;
		b=n;
		while(n!=0)
		{
			r=m%n;
			m=n;
			n=r;
		}
		printf("%d\n",a*b/m);
	}
	return 0;
}