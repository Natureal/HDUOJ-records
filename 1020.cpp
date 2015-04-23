////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 00:29:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	char a[10001];
	int i,count,n,l;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		l=strlen(a);
		count=1;
		for(i=0;i<l;i++)
		{
			if(a[i]==a[i+1])
				count++;
			else
			{
				if(count==1)
					printf("%c",a[i]);
				else
					printf("%d%c",count,a[i]);
				count=1;
			}
		}
		printf("\n");
	}
	return 0;
}