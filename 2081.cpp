////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-19 17:26:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2081
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i;
	char a[12];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		a[0]='6';
		for(i=1;i<=5;i++)
		{
			a[i]=a[5+i];
		}
		a[6]='\0';
		printf("%s\n",a);
	}
	return 0;
}