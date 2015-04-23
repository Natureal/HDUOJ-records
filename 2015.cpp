////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-15 16:51:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2015
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,n,m,sum,count,t;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		t=sum=count=0;
		for(i=1;i<=n;i++)
		{
			t+=2;
			sum+=t;
			count++;
			if(i == n)
			{
				printf("%d\n",sum/count);
			}
			else if(count == m)
			{
				printf("%d ",sum/m);
				count=0;
				sum=0;
			}
		}
	}
	return 0;
}