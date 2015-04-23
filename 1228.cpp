////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 23:17:40
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1228
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char num[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int search(char *x)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(0==strcmp(x,num[i]))
			break;
	}
	return i;
}
int main()
{
	int s1,s2;
	char a[6];
	while(1)
	{
		s1=s2=0;
		while(scanf("%s",a) && strcmp(a,"+")!=0)
		{
			s1=s1*10+search(a);
		}
		while(scanf("%s",a) && strcmp(a,"=")!=0)
		{
			s2=s2*10+search(a);
		}
		if(0==s1 && 0==s2)
		{
			return 0;
		}
		else
		{
			printf("%d\n",s1+s2);
		}
	}
	return 0;
}