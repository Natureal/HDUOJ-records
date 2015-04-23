////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 23:31:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2037
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a[100][24]={0},i,j,n,k,temp,count,ed;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a[i][0],&a[i][1]);
		}
		for(i=0;i<n-1;i++)
		{
			k=i;
			for(j=i+1;j<n;j++)
			{
				if(a[j][1]<a[k][1])
				{
					k=j;
				}
			}
			if(k!=i)
			{
			temp=a[i][1];
			a[i][1]=a[k][1];
			a[k][1]=temp;
			temp=a[i][0];
			a[i][0]=a[k][0];
			a[k][0]=temp;
			}
		}
		ed=0;
		for(i=0,count=0;i<n;i++)
		{
			if(a[i][0]>=ed)
			{
				ed=a[i][1];
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}