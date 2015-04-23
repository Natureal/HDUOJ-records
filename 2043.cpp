////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 00:39:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2043
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int m,l,i,s1,s2,s3,s4;
	char a[51];
	scanf("%d",&m);
	getchar();
	while(m--)
	{
		s1=s2=s3=s4=0;
		gets(a);
		l=strlen(a);
		if(l<8||l>16)
		{
			printf("NO\n");
			continue;
		}
		for(i=0;i<l;i++)
		{
			if(a[i]>='A'&&a[i]<='Z')
				s1=1;
			else if(a[i]>='a'&&a[i]<='z')
				s2=1;
			else if(a[i]>='0'&&a[i]<='9')
				s3=1;
			else if(a[i]=='~'||a[i]=='!'||a[i]=='@'||a[i]=='#'||a[i]=='$'||a[i]=='%'||a[i]=='^')
				s4=1;
			else
			{
				break;
			}
		}
		if(i==l && s1+s2+s3+s4 >= 3)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}