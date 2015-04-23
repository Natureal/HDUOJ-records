////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-19 22:57:57
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2087
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define N 1001
int main()
{
	int i,j,l1,l2,num;
	char a[N],b[N];
	while(scanf("%s",a)!=EOF && strcmp(a,"#")!=0)
	{
		scanf("%s",b);
		num=0;
		l1=strlen(a);
		l2=strlen(b);
		for(i=0;i<=l1-l2;i++)
		{
			for(j=0;j<l2;j++)
			{
				if(b[j]!=a[i+j]) break;
			}
			if(j>=l2)
			{
				num++;
				i+=l2-1;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}