////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-26 23:50:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1396
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a[501],i;
	while(scanf("%d",&n)!=EOF)
	{
		a[1]=1;
		a[2]=5;
		for(i=3;i<=500;i++)
		{
				if(i%2)
					a[i]=a[i-1]+2*i-1+i*(i-1)/2+(i-1)*(i-3)/4;
				else
                    a[i]=a[i-1]+2*i-1+i*(i-1)/2+(i-2)*(i-2)/4;
		}
		printf("%d\n",a[n]);
	}
	return 0;
}