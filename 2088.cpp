////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-20 23:44:27
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2088
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int i,aver,sum,n,a[51],flag=1;
	while(scanf("%d",&n)!=EOF && n)
	{
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		aver=sum/n;
		sum=0;
		for(i=0;i<n;i++)
		{
			sum+=labs(aver-a[i]);
		}
		if(flag) printf("%d\n",sum/2);
		else printf("\n%d\n",sum/2);
		flag=0;
	}
	return 0;
}