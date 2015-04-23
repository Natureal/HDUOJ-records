////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 01:20:44
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2024
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,t;
	char a[51];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
			gets(a);
			t=1;
			if((a[0]=='_'||(a[0]>='A'&&a[0]<='Z')||(a[0]>='a'&&a[0]<='z'))==0)
			{
				printf("no\n");
				continue;
			}
			else
			{
				for(i=1;a[i]!='\0';i++)
				{
					if(0==(a[i]=='_'||(a[i]>='A'&&a[i]<='Z')||(a[i]>='a'&&a[i]<='z')||(a[i]>='0'&&a[i]<='9')))
					{
						t=0;
						break;
					}
				}
				if(t)
					printf("yes\n");
				else
					printf("no\n");
			}
		}
	return 0;
}