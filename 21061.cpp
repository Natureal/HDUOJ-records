////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 14:28:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2106
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	_int64 n,a,b,t,sum;
	while(scanf("%I64d",&n)!=EOF)
	{
		sum=0;
		while(n--)
		{
			scanf("%I64d(%I64d)",&a,&b);
			t=1;
			while(a)
			{
				sum+=(a%10)*t;//b需要保持原值！！！！
				t*=b;
				a/=10;
			}
		}
		printf("%I64d\n",sum);
	}
	return 0;
}