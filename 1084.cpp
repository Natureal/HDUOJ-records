////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-12 23:26:48
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1084
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,j,y,k[100],t[100],g[100],count,count1,count2,h,m,s,i,x[5][100];
	while(scanf("%d",&n)!= EOF )
	{
		if( n < 0)
			break;
		for(j=0;j<5;j++)
		{
			for(i=0;i<100;i++)
				x[j][i] = 0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d %d:%d:%d",&k[i],&h,&m,&s);
			g[i] = 50 + 10*k[i];
			t[i] = h*60*60 + m*60 + s;
		}
		for(i=0;i<n;i++)
		{
			x[k[i]][i]=t[i];
		}
		for(j=0;j<5;j++)
		{
			count = 0;
			for(i=0;i<n;i++)
			{
				if(x[j][i]!=0)
				{
					count++;
				}
			}
			count1 = count / 2; 
			for(i=0;i<n;i++)
			{
				if(x[j][i]!=0)
				{
					count2 = 0;
					for(y=0;y<n;y++)
					{
						if(x[j][i] < x[j][y] && x[j][y] != 0)
							count2++;
					}
					if(count2 >= count - count1 && g[i]!=100)
					{
						g[i]+=5;
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d\n",g[i]);
		}
		printf("\n");
	}
	return 0;
}