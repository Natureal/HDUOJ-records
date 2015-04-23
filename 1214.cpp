////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-18 09:21:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1214
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int arr[32767+5];
void init()
{
	arr[1]=0;
	for(int i=2;i<=32767;i++)
	{
		arr[i]=arr[i-1]+i-1;
	}
	return;
}
int main()
{
	int n;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",arr[n/2]+arr[n-n/2]);
	}
	return 0;
}