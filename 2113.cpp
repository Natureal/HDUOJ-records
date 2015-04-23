////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-22 00:16:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2113
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,sum,flag=1;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		while(n!=0)
		{
			a=n%10;
			if(0==a%2) sum+=a;
			n/=10;
		}
		if(flag) printf("%d\n",sum);
		else printf("\n%d\n",sum);
		flag=0;
	}
	return 0;
}