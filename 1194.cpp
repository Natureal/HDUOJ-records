////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 17:40:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1194
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if((a%2==0&&b%2!=0)||(a%2!=0&&b%2==0)||(a<=b))
			printf("impossible\n");
		else
		{
			c=(a+b)/2;
			d=(a-b)/2;
			if(c>=d)printf("%d %d\n",c,d);
			else printf("%d %d\n",d,c);
		}
	}
	return 0;
}