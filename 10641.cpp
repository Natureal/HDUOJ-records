////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-17 23:30:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	double sum=0,a,k;
	k=12;
	while(k--)
	{
		scanf("%lf",&a);
		sum+=a;
	}
	printf("$%.2lf\n",sum/12);
	return 0;
}