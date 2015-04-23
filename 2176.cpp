////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-19 21:02:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2176
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1020KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int a[200005];
int main()
{
	int m,c;
	while(scanf("%d",&m)!=EOF && m)
	{
		c = 0;
		for(int i = 1;i <= m;i ++)
		{
			scanf("%d",&a[i]);
			c ^= a[i];
		}
		if(c == 0)
			printf("No\n");
		else
		{
			printf("Yes\n");
			for(int i = 1;i <= m;i ++)
			{
				int temp = c ^ a[i];
				if(temp < a[i])
				{
					printf("%d %d\n",a[i],temp);
				}
			}
		}
	}
	return 0;
}