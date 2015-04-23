////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 15:48:02
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2028
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,a[100],i,k,k1;
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&a[0]);
		k=a[0];
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			k1=k;
			k=k>a[i]?k:a[i];
			for(;;k++)
			{
				if(0==k%k1 && 0==k%a[i])
					break;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}