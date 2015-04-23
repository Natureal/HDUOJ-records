////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 00:51:08
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1061
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	_int64 i,t,n,r,m;
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%I64d",&n);
		m=n%20;
		r=m;
		for(i=1;i<m;i++)
		{
			r=r*m%10;
		}
		printf("%I64d\n",r);
	}
	return 0;
}