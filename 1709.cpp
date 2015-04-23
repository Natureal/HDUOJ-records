////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-25 00:22:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1709
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:308KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
int c1[10005],c2[10005];
int wei[105];
int main()
{
	int i,j,k,n,m,sum,flag,count;
	while(scanf("%d",&n)!=EOF)
	{
		flag=1;
		count=0;
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&wei[i]);
			sum+=wei[i];
		}
		memset(c2,0,sizeof(c2[0])*sum);//此处不能用sizeof(c2)，会超时，要优化！！
		memset(c1,0,sizeof(c1[0])*sum);
		/*for(i=0;i<=sum;i+=wei[1])
		{
			c1[i]=1;
		}*/
		c1[wei[1]]=1;
		c1[0]=1;
		m=wei[1];
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=m;j++)//此处进行了优化，比for(j=0;j<=sum;j++)更好
			{
				for(k=0;k<=wei[i];k+=wei[i])
				{
					c2[j+k]+=c1[j];
					c2[abs(k-j)]+=c1[j];//天平两边都可以放砝码！！！
				}
			}
			m+=wei[i];
		   for(j=0;j<=m;j++)
	    	{
		    	c1[j]=c2[j];
		    	c2[j]=0;
	    	}
		}
		for(i=1;i<=sum;i++)
		{
			if(c1[i]==0) count++;
		}
		printf("%d\n",count);
		if(count!=0)
		{
	    	for(i=1;i<=sum;i++)
		    {
		    	if(c1[i]==0)
		    	{
		  	    	if(flag) printf("%d",i);
			    	else printf(" %d",i);
			     	flag=0;
		    	}
	      	}
	        puts("");
		}
	}
	return 0;
}