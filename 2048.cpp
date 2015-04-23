////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 14:10:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
float fac(int x)
{
	if(1==x)
		return 1;
	else
		return x*fac(x-1);
}
int main()
{
	int n,c,i;
	float p[21]={0,0,1};
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		for(i=3;i<=n;i++)
		{
			p[i]=(i-1)*(p[i-1]+p[i-2]);
		}
		printf("%.2f%%\n",p[n]*100/fac(n));
	}
	return 0;
}