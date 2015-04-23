////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 14:38:13
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2049
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
_int64 fac(int x)
{
	if(0==x)
		return 1;
	else
		return x*fac(x-1);
}
int main()
{
	int c,n,m,i;
	_int64 a[21]={0,0,1},k;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&m,&n);
		k=fac(m)/(fac(n)*fac(m-n));
		for(i=3;i<=n;i++)
		{
			a[i]=(i-1)*(a[i-1]+a[i-2]);
		}
		printf("%I64d\n",a[n]*k);
	}
	return 0;
}