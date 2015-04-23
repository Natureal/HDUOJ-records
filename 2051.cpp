////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 15:39:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2051
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a[10],k,i;
	while(scanf("%d",&n)!=EOF)
	{
		k=n;
		for(i=0;k!=0;i++)
		{
			a[i]=k%2;
			k=k/2;
		}
		while(i--)//如果n转换成二进制只有一位，这样写可使这种情况下进入循环，i再减一。
		{
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}