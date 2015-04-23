////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-10 19:55:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2040
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,b,A,B,sum1,sum2,i;
	int judge1,judge2;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			sum1=sum2=0;
			judge1=judge2=0;
			scanf("%d %d",&A,&B);
			a=A/2;
			b=B/2;
			for(i=1;i<=a;i++)
			{
				if(0 == A%i)
					sum1+=i;
			}
			if( sum1 == B)
				judge1 = 1;
			for(i=1;i<=b;i++)
			{
				if(0 == B%i)
					sum2+=i;
			}
			if( sum2 == A)
				judge2 = 1;
			if( 1 == judge1 && 1 == judge2)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}