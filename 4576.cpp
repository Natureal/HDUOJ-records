////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-21 22:33:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4576
////Problem Title: 
////Run result: Accept
////Run time:3187MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#define Range 200
double c[2][Range + 1];
int n,m,l,r,w;
int main()
{
	int i,j;
	double pro,anspro;
	while(scanf("%d %d %d %d",&n,&m,&l,&r)!=EOF)
	{
		if(n == 0 && m == 0 && l == 0 && r == 0)
			break;

		memset(c,0,sizeof(c));
		//记为0到n-1
		c[0][0] = 1;
		for(i = 0;i < m;i ++)
		{
			scanf("%d",&w);
			w = w % n;
			int k1 = i & 1;//偶数为0,奇数为1
			for(j = 0;j < Range;j ++)
			{
				if(c[k1][j] > 0)
				{
					c[!k1][(j - w + n) % n] +=  c[k1][j] * 0.5;
					c[!k1][(j + w) % n] += c[k1][j] * 0.5;
					c[k1][j] = 0;
				}
			}
		}
		int ak = m & 1;
		anspro = 0;
		for(i = l - 1;i <= r - 1;i ++)
		{
			anspro += c[ak][i];
		}
		printf("%.4lf\n",anspro);
	}
	return 0;
}
