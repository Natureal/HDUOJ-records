////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-22 23:53:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2567
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int len,k,i,t;
	char a[50],b[50];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",a,b);
		len=strlen(a);
		k=len/2;
		for(i=0;i<k;i++)
		{
			printf("%c",a[i]);
		}
		printf("%s",b);
		for(i=k;i<len;i++)
		{
			printf("%c",a[i]);
		}
		puts("");
	}
	return 0;
}