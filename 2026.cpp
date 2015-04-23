////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 12:47:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2026
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define N 101
int main()
{
	int t,l,i;
	char a[N];
	while(gets(a))
	{
		l=strlen(a);
		t=1;
		for(i=0;i<l;i++)
		{
			if(a[i]==' ')
			{
				t=1;
				printf("%c",a[i]);
				i++;
			}
			if(t)
			{
				printf("%c",a[i]-32);
				t=0;
			}
			else
			{
				printf("%c",a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}