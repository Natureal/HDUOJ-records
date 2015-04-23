////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-19 21:57:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2078
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,n,i,m,a[100],min;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		min=a[0];
		for(i=1;i<n;i++)
		{
			min=min<a[i]?min:a[i];
		}
		printf("%d\n",(100-min)*(100-min));
	}
	return 0;
}