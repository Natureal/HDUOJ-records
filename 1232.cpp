////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-15 21:27:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1232
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int father[1005];
int find(int x)
{
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}
int main()
{
	int i,count,x,y;
	int n,m;
	while(scanf("%d",&n)!=EOF && n)
	{
		scanf("%d",&m);
		for(i=1;i<=n;i++)
		{
			father[i]=i;
		}
		while(m--)
		{
			scanf("%d %d",&x,&y);
			x=find(x);
			y=find(y);
			father[x]=y;
		}
		count=0;
		for(i=1;i<=n;i++)
		{
			if(father[i]==i)
			{
				count++;
			}
		}
		printf("%d\n",count==0?count:count-1);
	}
	return 0;
}