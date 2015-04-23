////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 18:04:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2187
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>

void sort(int p[],int h[],int m)
{
	int i,j,k,temp;
	for(i=0;i<m-1;i++)
	{
		k=i;
		for(j=i+1;j<m;j++)
		{
			if(p[j]<p[k])
				k=j;
		}
		if(k!=i)
		{
			temp=p[i];
			p[i]=p[k];
			p[k]=temp;

			temp=h[i];
			h[i]=h[k];
			h[k]=temp;
		}
	}
	return;
}

int main()
{
	int c,i,n,m,p[1005],h[1005];
	double re,k;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&p[i],&h[i]);
		}
		sort(p,h,m);
		re=0;
		for(i=0;i<m;i++)
		{
			if(n<=p[i]*h[i])
			{
				k=1.0*n/p[i];
				re+=k;
				break;
			}
			else
			{
				n-=h[i]*p[i];
				re+=h[i];
			}
		}
		printf("%.2lf\n",re);
	}
	return 0;
}