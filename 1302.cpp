////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-14 00:49:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1302
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	double h,u,d,f,l;
	int i;
	while(scanf("%lf%lf%lf%lf",&h,&u,&d,&f)!=EOF && h)
	{
		f=(f*u)/100;
		l=0;
		for(i=1;;i++)
		{
			l+=u;
			l-=d;
			u=u-f;
			if(l<0)
			{
				printf("failure on day %d\n",i);//????
				break;
			}
			if(l>=h)
			{
				printf("success on day %d\n",i-1);
				break;
			}
		}
	}
	return 0;
}