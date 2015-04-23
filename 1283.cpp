////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-13 15:52:29
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1283
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define N 200
int main()
{
	int m1,m2,r1,r2,r3,i;
	char a[N];
	while(scanf("%d %d",&m1,&m2)!=EOF)
	{
		i = 0;
		r1=r2=r3=0;
		scanf("%s",a);
		while(a[i] != '\0')
		{
			if(a[i] == 'A')
			{
				r1 = m1;
			}
			else if(a[i] == 'B')
			{
				r2 = m2;
			}
			else if(a[i] == 'C')
			{
				m1 = r3;
			}
			else if (a[i]=='D')
			{
				m2=r3;
			}
			else if(a[i]=='E')
			{
				r3=r1+r2;
			}
			else if(a[i]=='F')
			{
				r3=r1-r2;
			}
			i++;
		}
		printf("%d,%d\n",m1,m2);
	}
	return 0;
}