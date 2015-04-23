////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-10-30 17:52:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1008
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,a[101]={0},n,t;
	while(scanf("%d",&n)!=EOF&&n)
	{
		t=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>a[i-1])
				t=t+(a[i]-a[i-1])*6+5;
			else
				t=t+(a[i-1]-a[i])*4+5;
		}
		printf("%d\n",t);
	}
	return 0;
}
