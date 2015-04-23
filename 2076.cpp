////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-17 23:43:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2076
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,h,m,s;
	double j,jh,jm;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&h,&m,&s);
		jh=30.0*(h%12)+1.0*m/2+1.0*s/120;
		jm=6.0*m+1.0*s/10;
		j=jh-jm;
		if(j<0)
			j=-j;
		if(j>180)
			j=360.0-j;
		printf("%d\n",(int)j);
	}
	return 0;
}