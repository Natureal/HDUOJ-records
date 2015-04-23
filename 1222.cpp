////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-28 19:47:57
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1222
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1222.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月28日 星期五 19时32分33秒
 ************************************************************************/

#include<stdio.h>
int gcd(int a,int b)
{
	if(b==0)return a;
	if(a<b)
	{
		int temp;
		temp=a;
		a=b;
		b=temp;
	}
	return gcd(b,a%b);
}
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(gcd(a,b)==1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}