////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-23 17:52:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2568
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,n,num;
	scanf("%d",&t);
	while(t--)
	{
		num=0;
		scanf("%d",&n);
		while(n!=0)
		{
			if(0==n%2) n/=2;
			else
			{
				n--;
				num++;
			}
		}
		printf("%d\n",num);
	}
	return 0;
}