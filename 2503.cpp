////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-09 00:23:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2503
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,i,k,a1,b1,a2,b2,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		a=a1*b2+a2*b1;
		b=b1*b2;
		k=a>b?b:a;
		for(i=k;i>0;i--)
		{
			if(0==a%i && 0==b%i)
			{
				a/=i;
				b/=i;
				break;
			}
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}