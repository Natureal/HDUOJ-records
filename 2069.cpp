////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-31 20:24:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2069
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,s,a,ak,b,bk,c,ck,d,e;
	while(scanf("%d",&n)!=EOF)
	{
		s=0;
		for(a=0;50*a<=n;a++)
		{
			ak=n-50*a;
			for(b=0;25*b<=ak;b++)
			{
				bk=n-50*a-25*b;
				for(c=0;10*c<=bk;c++)
				{
					ck=n-50*a-25*b-10*c;
					for(d=0;5*d<=ck;d++)
					{
						e=ck-5*d;
						if(e>=0 && a+b+c+d+e<=100)
							s++;
					}
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}