////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-18 14:14:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2057
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	_int64 a,b,s;
	while(scanf("%I64X %I64X",&a,&b)!=EOF)
	{
		s=a+b;
		if(s<0)
		{
			s=-s;
		    printf("-%I64X\n",s);
		}
		else
		{
			printf("%I64X\n",s);
		}
	}
	return 0;
}