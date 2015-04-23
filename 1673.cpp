////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-09 23:01:37
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1673
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,min,max,n,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&a);
		min=max=a;
		while(--n)
		{
			scanf("%d",&a);
			min=min<a?min:a;
			max=max>a?max:a;
		}
		printf("%d\n",2*(max-min));
	}
	return 0;
}