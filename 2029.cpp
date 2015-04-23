////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 16:21:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2029
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
	int n,l,i,t;
	char a[N];
	scanf("%d",&n);
		while(n--)
		{
		scanf("%s",a);
		l=strlen(a);
	    for(i=0;i<(l/2);i++)
		{
			if(a[i]==a[l-1-i])
				t=1;
			else
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
	return 0;
}