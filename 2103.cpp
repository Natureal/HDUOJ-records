////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 12:35:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2103
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,n,m,i,flag,a;
	_int64 sum,fine;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		fine=10000;
		flag=0;
		scanf("%d %d",&m,&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if(i>m||flag)
			{
				sum+=fine;
				fine*=2;
			}
			if(a==1)
				flag=1;
		}
		printf("%I64d RMB\n",sum);
	}
	return 0;
}