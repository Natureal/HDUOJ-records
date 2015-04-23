////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-08 23:39:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2010
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int m,n,i,count,a,b,c;
	while(2==scanf("%d %d",&m,&n))
	{
		for(i=m,count=0;i<=n;i++)
		{
			a=i/100;
			b=(i%100)/10;
			c=i%10;
			if( i == a*a*a + b*b*b + c*c*c)
			{
				count++;   //最后一个输出的水仙花数后面没有空格！！！
				if(count == 1)
				{
				printf("%d",i);
				}
				else
				{
				printf(" %d",i);
				}
			}
		}
		if(count == 0)
		{
			printf("no");
		}
		printf("\n");
	}
	return 0;
}