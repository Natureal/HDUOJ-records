////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-23 23:41:14
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2156
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2156.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月23日 星期日 23时17分24秒
 ************************************************************************/

#include<stdio.h>
#include <math.h>
int main()
{
	int n,i,j;
	double sum,temp;
	while(scanf("%d",&n)!=EOF&&n)
	{
		sum=1;
		temp=0;
		for(i=2;i<=n;i++)
		{
			temp+=1.0/i;
			sum+=2*temp+1;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}