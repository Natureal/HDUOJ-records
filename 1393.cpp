////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-26 22:19:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1393
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include<stdio.h>
int main()
{    
    int s,d,g,k;
	while(scanf("%d%d",&s,&d)!=EOF)
	{
		if(s==0&&d==0) break;
		g=0;k=0;
		while(k<=60)		{    
		    if(s==0)
		    {
			  g=1;break;
		    }
		    s=s+s*d;
		    k=k+1;
		    s=s%60;
		}
		if(k==61) printf("Impossible\n");
		else
		printf("%d\n",k);
	}
}