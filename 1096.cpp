////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-07 17:05:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1096
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,i,a,sum[100]={0};
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&a);
				sum[i]+=a;
			}
		}
	  for(i=0;i<n;i++)
	   {
		printf("%d\n",sum[i]);
		if(i!=n-1)
		{
			printf("\n");
		}
	   }
	}
	return 0;
}