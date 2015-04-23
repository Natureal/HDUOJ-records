////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-28 09:52:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2090
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	double a,b,sum=0;
	char arr[100];
	while(scanf("%s%lf%lf",arr,&a,&b)!=EOF)
	{
		sum+=a*b;
	}
	printf("%.1lf\n",sum);
	return 0;
}