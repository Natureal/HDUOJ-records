////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-19 14:38:23
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1017
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int N,n,m,i,j,count,ca;
	double temp;
	scanf("%d",&N);
	while(N--)
	{
		ca=1;
		while(scanf("%d%d",&n,&m)!=EOF && n||m)
		{
			count=0;
			for(i=1;i<n-1;i++)
			{
				for(j=i+1;j<n;j++)
				{
					temp=(double)(i*i+j*j+m)/(i*j);
					if(temp-(int)temp==0)count++;
				}
			}
			printf("Case %d: %d\n",ca,count);
			ca++;
		}
		if(N!=0)puts("");
	}
	return 0;
}