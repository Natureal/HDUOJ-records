////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-20 00:31:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2162
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a,s,i=1;
	while((scanf("%d",&n)!=EOF)&& n>0)
	{
		s=0;
		while(n--)
		{
			scanf("%d",&a);
			s+=a;
		}
		printf("Sum of #%d is %d\n",i,s);
		i++;
	}
	return 0;
}