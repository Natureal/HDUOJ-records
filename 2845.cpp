////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-01 23:29:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2845
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:360KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXN 200000
int dpr[MAXN+5],dpc[MAXN+5];
int max_int(int a,int b)
{
	return a > b ? a : b;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
				scanf("%d",dpc+j);
			for(int j=2;j<=n;j++)//从第二个开始，刚好可以全部考虑
			{
				dpc[j]=max_int(dpc[j-2]+dpc[j],dpc[j-1]);
			}
			//dpc[n]为该行最大不连续子序列和
			dpr[i]=dpc[n];
		}
		for(int i=2;i<=m;i++)
		{
			dpr[i]=max_int(dpr[i-2]+dpr[i],dpr[i-1]);
		}
		printf("%d\n",dpr[m]);
	}
	return 0;
}