////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 23:24:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1235
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a[1000],i,t,num;
	while(scanf("%d",&n)!=EOF && n )
	{
		num=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&t);
		for(i=0;i<n;i++)
		{
			if(a[i]==t)
				num++;
		}
		printf("%d\n",num);
	}
	return 0;
}