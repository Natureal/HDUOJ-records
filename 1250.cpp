////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-25 22:26:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1250
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:25300KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1250.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月25日 星期二 22时12分57秒
 ************************************************************************/

#include<stdio.h>
int a[8000][800];
int main()
{
	int i,j,n,k;
	a[1][0]=1;
	a[2][0]=1;
	a[3][0]=1;
	a[4][0]=1;
	k=0;
	for(i=5;i<8000;i++)
	{
		for(j=0;j<800;j++)
		{
			k+=a[i-1][j]+a[i-2][j]+a[i-3][j]+a[i-4][j];
			a[i][j]=k%10000;
			k/=10000;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		for(i=799;i>=0;i--)
		{
			if(a[n][i]!=0)
			{
				break;
			}
		}
		printf("%d",a[n][i]);
		for(j=i-1;j>=0;j--)
		{
			printf("%04d",a[n][j]);
		}
		puts("");
	}
	return 0;
}