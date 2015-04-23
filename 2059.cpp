////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-14 22:09:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2059
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>  //用正常算法写为什么错？
#define MAX 101

double min(double x,double y)
{
	return x>y?y:x;
}

int main()
{
	int i,j,l,n,c,t,vr,vt1,vt2,a[MAX],s;
	double tr,tt,dp[MAX];
	while(scanf("%d",&l)!=EOF)
	{
		tt=0;
		scanf("%d%d%d",&n,&c,&t);
		scanf("%d%d%d",&vr,&vt1,&vt2);
		tr=1.0*l/vr;
		/*printf("tr=%.2lf\n",tr);*/
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		a[0]=0;
		a[n+1]=l;
		dp[0]=0;
		for(i=1;i<=n+1;i++)
		{
			dp[i]=2147483647;
			for(j=0;j<i;j++)
			{
				s=a[i]-a[j];
				if(s>c)
				{
					tt=(double)c/vt1+((double)s-c)/vt2;
				}
				else
				{
					tt=(double)s/vt1;
				}
				tt+=dp[j];
			    if(j>0)
		        {
		     		tt+=t;
		     	}
		     	dp[i]=min(dp[i],tt);
	    	}
		}
		if(dp[n+1]<tr)
			printf("What a pity rabbit!\n");
		else
			printf("Good job,rabbit!\n");
	}
	return 0;
}