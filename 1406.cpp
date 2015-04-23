////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-28 09:08:58
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1406
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,n1,n2,i,j,sum,num,s;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&n1,&n2);
		num=0;
		s=n1+n2;
		n1=n1<n2?n1:n2;
		n2=s-n1;
		for(i=n1;i<=n2;i++)
		{
			sum=1;
			for(j=2;j<=i/2;j++)
			{
				if(0==i%j)
					sum+=j;
			}
			if(sum==i)
				num++;
		}
		printf("%d\n",num);
	}
	return 0;
}