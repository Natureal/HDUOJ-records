////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-19 14:58:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1856
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:78612KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define MAX 10000050
int father[MAX+1];
int    sum[MAX+1];
int find(int x)
{
	if(father[x]!=x)father[x]=find(father[x]);
	return father[x];
}
int main()
{
	int n,a,b,max;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=MAX;i++)
		{
			father[i]=i;
			sum[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			a=find(a);
			b=find(b);
			if(a!=b)
			{
				father[b]=a;
				sum[a]+=sum[b];
			}
		}
		max=sum[1];
		for(int i=2;i<=MAX;i++)
		{
			max=sum[i]>max?sum[i]:max;
		}
		printf("%d\n",max);
	}
	return 0;
}