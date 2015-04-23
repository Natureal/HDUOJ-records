////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-23 12:42:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1087
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int val[1005],sum[1005];
int main()
{
	int i,j,n;
	int max;
	while(~scanf("%d",&n)&&n)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d",&val[i]);
                }
		max=val[1];
         for(i=1;i<=n;i++)
    {
        	sum[i]=val[i];
			for(j=1;j<i;j++)
			{ 
			 	if(val[i]>val[j]&&sum[j]+val[i]>sum[i]) 
				{
						sum[i]=sum[j]+ val[i]; 
				}
			}
			if(max<sum[i])
			{
				max=sum[i];
			}
 		}
	printf("%d\n",max);
	}
	return 0;
}