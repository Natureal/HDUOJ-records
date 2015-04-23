////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-18 23:12:35
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int n,m,j,i;
	while(scanf("%d %d",&n,&m)!=EOF && (n||m))
	{
		for(j=sqrt(2.0*m);j>=1;j--)
		{
			i=(2*m/j+1-j)/2;
			if((2*i+j-1)*j/2==m)
				printf("[%d,%d]\n",i,i+j-1);
		}
		printf("\n");
	}
	return 0;
}