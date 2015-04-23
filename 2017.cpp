////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-15 17:07:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2017
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define N 1000
int main()
{
	int n,i,l,count;
	char a[N];
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%s",a);
			l=strlen(a);
			count=0;
			for(i=0;i<l;i++)
			{
				if(a[i]>=48 && a[i]<=57)
					count++;
			}
			printf("%d\n",count);
		}
	}
	return 0;
}