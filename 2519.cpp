////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 22:47:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2519
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,n,m,mi;
	unsigned _int64 re,temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(m>n)printf("0\n");
		else
		{
			re=1;
			temp=1;
			mi=m<n-m?m:n-m;
			for(int i=1;i<=mi;i++)
			{
				temp*=i;
			}
			for(int i=n-mi+1;i<=n;i++)
			{
				re*=i;
			}
			printf("%I64d\n",re/temp);
		}
	}
	return 0;
}