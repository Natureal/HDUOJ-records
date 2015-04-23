////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-15 17:02:08
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2016
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,n,a[100],sign,temp;
	while(scanf("%d",&n)!=EOF && n)
	{
		sign=0;
		scanf("%d",&a[0]);
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<a[sign])
			{
				sign=i;
			}
		}
		temp=a[0];
		a[0]=a[sign];
		a[sign]=temp;
		for(i=0;i<n-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n-1]);
	}
	return 0;
}