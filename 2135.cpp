////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-08 12:46:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2135
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,j,n,m,state;
	char a[11][11],b[11][11];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		getchar();
		if(m>=0) state=m%4;
		else state=(4-(-m)%4)%4;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%c",&a[i][j]);
			}
			getchar();
		}
	    if(state==1)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					b[j][n-i+1]=a[i][j];
				}
			}
		}
		else if(state==2)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					b[n-i+1][n-j+1]=a[i][j];
				}
			}
		}
		else if(state==3)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					b[n-j+1][i]=a[i][j];
				}
			}
		}
		if(state==0)
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					printf("%c",a[i][j]);
				}
			    puts("");
			}
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					printf("%c",b[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}
