////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-12 22:11:32
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2148
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int s[1000],n,k,i,t,count;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%d",&s[i]);
		}
		for(i=0;i<n;i++)
		{
			if(s[i]>s[k-1]) count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
