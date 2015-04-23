////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-04 23:01:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1570
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int fac(int x)
{
	if(0==x)
		return 1;
	else
		return x*fac(x-1);
}
int main()
{
	int t,n,m;
	char c;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		scanf("%c%d%d",&c,&n,&m);
		getchar();
		if('A'==c)
		{
			printf("%d\n",fac(n)/fac(n-m));
		}
		else if('C'==c)
		{
			printf("%d\n",fac(n)/fac(n-m)/fac(m));
		}
	}
	return 0;
}