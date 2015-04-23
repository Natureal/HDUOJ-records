////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-18 23:10:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2058
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int n,m,j;
	float i;
	while(scanf("%d %d",&n,&m)!=EOF && (n||m))
	{
		for(j=sqrt(2.0*m);j>=1;j--)
		{
			i=(2.0*m/j+1-j)/2;
			if((int)i==i)
				printf("[%d,%d]\n",(int)i,(int)i+j-1);
		}
		printf("\n");
	}
	return 0;
}