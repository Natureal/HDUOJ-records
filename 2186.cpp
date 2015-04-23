////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 17:26:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2186
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int c,n;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		printf("%d\n",(n/2+9)/10+((n-n/2)*2/3+9)/10+((n-n/2-(n-n/2)*2/3)+9)/10);
	}
	return 0;
}
