////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 12:36:19
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2025
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int l,t,i,j;
	char a[100];
	while(scanf("%s",a)!=EOF)
	{
		l=strlen(a);
		for(i=0;i<l;i++)
		{
			t=0;
			for(j=0;j<l;j++)//i和j分清楚 别打错！
			{
				if(a[i]>=a[j])
					t=1;
				else
				{
					t=0;
					break;
				}

			}
			printf("%c",a[i]);
			if(t)
				printf("(max)");
		}
		printf("\n");
	}
	return 0;
}