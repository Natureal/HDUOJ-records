////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-24 15:10:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1164
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:488KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1164.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月24日 星期一 14时38分23秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int num[66000];
int main()
{
	int i,j,x;
	//建素数谱
	memset(num,0,sizeof(num));
	for(i=2;i<300;i++)
	{
		for(j=i*i;j<=65535;j+=i)
		{
			num[j]=1;
		}
	}
	while(scanf("%d",&x)!=EOF)
	{
		while(x!=1)
		{
			for(i=2;i<=65535;i++)
			{
				if(!num[i]&&0==x%i)
				{
					break;
				}
			}
			if(x/i==1) printf("%d\n",i);
			else printf("%d*",i);
			x/=i;
		}
	}
	return 0;
}