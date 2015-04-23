////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-22 13:24:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1038
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define P  3.1415927
int main()
{
	int i=1,r;
	double d,t,s,aver;
	while(1)
	{
		scanf("%lf %d %lf",&d,&r,&t);
		if(0==r)
		{
			break;
		}
		s=P*d*r/12/5280;
		aver=s/t*60*60;
		printf("Trip #%d: %.2lf %.2lf\n",i++,s,aver);
	}
	return 0;
}