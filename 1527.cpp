////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-18 21:24:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1527
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main()
{
	int a,b;
	double q;
	q = (1 + sqrt(5.0)) / 2;
	while(scanf("%d %d",&a,&b) != EOF)
	{
		if(a > b)
		{
			int temp;
			temp = a;
			a = b;
			b = temp;
		}
		if(a == (int)((b - a) * q))
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
	}
	return 0;
}