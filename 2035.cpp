////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 20:43:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2035
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b,t,i,s;
	while(scanf("%d %d",&a,&b)!=EOF && (a||b))
	{
		s=t=a%1000;
		for(i=1;i<b;i++)
		{
			s=(s*t)%1000;
		}
		printf("%d\n",s);
	}
	return 0;
}