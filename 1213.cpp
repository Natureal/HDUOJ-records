////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 21:42:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1213
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int father[1005];
int find(int x)
{
	if(father[x]!=x)father[x]=find(father[x]);
	return father[x];
}
int main()
{
	int t,n,m,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			father[i]=i;
		}
		while(m--)
		{
			scanf("%d%d",&a,&b);
			a=find(a);
			b=find(b);
			father[b]=a;
		}
		int count=0;
		for(int i=1;i<=n;i++)
		{
			if(father[i]==i)count++;
		}
		printf("%d\n",count);
	}
	return 0;
}