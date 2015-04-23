////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-19 23:39:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2074
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	char s[81][81],m[2];
	int n,q,i,j,flag,k,t=0;
	while(scanf("%d %c %c",&n,&m[0],&m[1])!=EOF)
	{
		flag=n/2%2;
		for(q=1;q<=n/2;q++)
		{
			k=n+2-2*q;
			for(i=q;i<=q+k-1;i++)
			{
				if(i==q || i==q+k-1)
				{
					for(j=q;j<=q+k-1;j++) s[i][j]=m[flag];
				}
				else
				{
					s[i][q]=s[i][q+k-1]=m[flag];
				}
			}
			flag=1-flag;
		}
	    s[1][1]=s[1][n]=s[n][1]=s[n][n]=' ';
		s[n/2+1][n/2+1]=m[0];
		if(t!=0)
		{
		puts("");
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%c",s[i][j]);
			}
			puts("");
		}
		t++;
	}
	return 0;
}