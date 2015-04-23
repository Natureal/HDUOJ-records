////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 00:54:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2044
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,t,i;
	long long f[50];
	scanf("%d",&n);
	f[1]=1,f[2]=2;
	while(n--)
	{
		scanf("%d %d",&a,&b);
		t=b-a;
		for(i=3;i<=t;i++)
		{
			f[i]=f[i-1]+f[i-2];
		}
		printf("%I64d\n",f[t]);
	}
	return 0;
}