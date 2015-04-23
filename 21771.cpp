////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-19 00:30:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2177
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
	int a,b,j,l,m,ak,bk,aj,aj2,al,al2,bl,bm,bm2,k;
	double q = (1 + sqrt(5.0) ) / 2;
	double r = (sqrt(5.0) - 1 ) / 2;
	double u = (3 - sqrt(5.0) ) / 2;
	double v = (3 + sqrt(5.0) ) / 2;

	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(a == 0 &&  b == 0)
			break;
		j = (int)(a * r);
		aj = (int)(j * q);
		aj2 = (int)((j + 1) * q);

		l = (int)(a * u);
		al = (int)(l * q);
		al2 = (int)((l + 1) * q);

		m = (int)(b * u);
		bm = (int)(m * v);
		bm2 = (int)((m + 1) * v);

		if(a == aj && b == aj + j)
		{
			printf("0\n");
		}
		else if(a == aj2 && b == aj2 + j + 1)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
			k = b - a;
			ak = (int) (k * q);
			bk = ak + k;
			printf("%d %d\n",ak,bk);
			
			if(a == aj && b > a + j)//以a为aj
			{
				printf("%d %d\n",aj,aj + j);
			}
			else if(a == aj + 1 && b> a + 1 + j + 1)
			{
				printf("%d %d\n",aj + 1,aj + 1 + j + 1);
			}
			bl = a;
			if(al + l == bl)//以a为bj
			{
				printf("%d %d\n",al,bl);
			}
			else if(al2 + l + 1 == bl)
			{
				printf("%d %d\n",al2,bl);
			}
			if(bm == b && bm != bl && bm != aj + j && bm != aj + 2 + j)//以b为bj，而b不可能为aj
			{
				printf("%d %d\n",bm - m,bm);
			}
			else if(bm2 == b && bm2 != aj + j && bm2 != aj + 2 + j)
			{
				printf("%d %d\n",bm2 - m - 1,bm2);
			}
		}
	}
	return 0;
}