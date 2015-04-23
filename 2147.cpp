////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-22 21:10:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2147
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:296KB
//////////////////System Comment End//////////////////
 #include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF && (n || m))
	{
		if(n % 2 && m % 2)
		{
			printf("What a pity!\n");
		}
		else
		{
			printf("Wonderful!\n");
		}
	}
	return 0;
}
