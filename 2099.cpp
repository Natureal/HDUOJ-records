////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-15 13:42:40
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2099
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,i,b,r1,r2,count;
	while(scanf("%d%d",&a,&b)!=EOF && a||b)
	{
		r1=(a*100)%b;
		count=0;
		for(i=0;i<100;i++)
		{
			r2=i%b;
			if(0==(r1+r2)%b)
			{
				if(i<10)
				{
					printf("0%d",i);
					count=1;
				}
				else
				{
					if(count==0)
					{
						printf("%d",i);
						count=1;
					}
					else
						printf(" %d",i);
				}
	    	}
		}
		puts("");
	}
	return 0;
}