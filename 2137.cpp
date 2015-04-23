////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-08 23:44:46
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2137
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,l,n;
	char a[85],b[85][85];
	while(scanf("%s %d",a,&n)!=EOF)
	{
		l=strlen(a);
		n%=8;
		if(n<0)
			n+=8;
		memset(b,' ',sizeof(b));
		if(n==0)
		{
			for(i=0;i<l;i++)
			{
				b[0][i]=a[i];
			}
		}
		else if(n==1)
		{
			for(i=0;i<l;i++)
			{
				b[l-i-1][i]=a[i];
			}
		}
		else if(n==2)
		{
			for(i=0;i<l;i++)
			{
				b[l-i-1][l/2]=a[i];
			}
		}
		else if(n==3)
		{
			for(i=0;i<l;i++)
			{
				b[l-i-1][l-i-1]=a[i];
			}
		}
		else if(n==4)
		{
			for(i=0;i<l;i++)
			{
				b[0][l-i-1]=a[i];
			}
		}
		else if(n==5)
		{
			for(i=0;i<l;i++)
			{
				b[i][l-i-1]=a[i];
			}
		}
		else if(n==6)
		{
			for(i=0;i<l;i++)
			{
				b[i][l/2]=a[i];
			}
		}
		else if(n==7)
		{
			for(i=0;i<l;i++)
			{
				b[i][i]=a[i];
			}
		}
		if(n==0 || n==4)
		{
			for(i=0;i<l;i++)
			{
				printf("%c",b[0][i]);
			}
			puts("");
		}
		else
		{
			for(i=0;i<l;i++)
			{
				for(j=0;j<l;j++)
				{
					printf("%c",b[i][j]);
					if(b[i][j]!=' ')
						break;
				}
				puts("");
			}
		}
	}
	return 0;
}