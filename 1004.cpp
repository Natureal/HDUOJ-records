////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-10 20:34:21
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1004
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define N 1000
int main()
{
	int n,i,j,count,max,s;
	char a[N][16];
	while(scanf("%d",&n),n)
	{
		max = 1;
		for(i=s=0;i<n;i++)
		{
			scanf("%s",a[i]);
			count = 0;
			if(i!=0)
			{
				for(j=i-1;j>=0;j--)
				{
				  if(strcmp(a[i],a[j]) == 0)
					  count++;
				}
				if(count > max)
				{
					max = count;
					s = i;
				}
			}
		}
		printf("%s\n",a[s]);
	}
	return 0;
}
