////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-24 16:05:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1212
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1212.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月24日 星期一 15时36分17秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
int main()
{
	char arr[1005];
	int l,a,b,i;
	while(scanf("%s",arr)!=EOF)
	{
		l=strlen(arr);
		scanf("%d",&b);
		for(a=i=0;i<l;i++)
		{
			a=(a*10+arr[i]-'0')%b;
		}
		printf("%d\n",a);
	}
	return 0;
}