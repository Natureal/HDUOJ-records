////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-19 00:07:20
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1005
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	long int a,b,n,f[100],i;
	while(scanf("%ld%ld%ld",&a,&b,&n)!=EOF && (a||b||n))
	{
		f[1]=f[2]=1;
		for(i=3;i<=48;i++)
		{
			f[i]=(a*f[i-1]+b*f[i-2])%7;
		}
		printf("%ld\n",f[n>48?n%48:n]);
	}
	return 0;
}