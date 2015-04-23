////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 00:01:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2041
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,f[100],i;
	f[0]=0,f[1]=1,f[2]=2;
	scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&m);
            if(m>=3)
			{
				for(i=3;i<m;i++)
				{
					f[i]=f[i-1]+f[i-2];
				}
			}
			printf("%d\n",f[m-1]);
		}
	return 0;
}