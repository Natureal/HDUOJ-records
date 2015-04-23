////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-28 09:39:20
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1407
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	int num,x,y;
	double z;
	while(scanf("%d",&num)!=EOF)
	{
		for(x=1;x<=sqrt(1.0*num/3);x++)
		{
			for(y=x;y<=sqrt((1.0*num-x*x)/2);y++)
			{
				z=sqrt(1.0*num-x*x-y*y);
				if((int)z==z)
				{
					printf("%d %d %d\n",x,y,(int)z);
					goto out;
				}
			}
		}
		out:;
	}
	return 0;
}