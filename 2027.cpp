////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 13:01:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2027
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,a,e,i,o,u,count,l;
	char x[101];
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		while(n--)
		{
		gets(x);
		l=strlen(x);
		a=e=i=o=u=0;
		for(count=0;count<l;count++)
		{
			if(x[count]=='a')
				a++;
			else if(x[count]=='e')
				e++;
			else if(x[count]=='i')
				i++;
			else if(x[count]=='o')
				o++;
			else if(x[count]=='u')
				u++;
		}
		printf("a:%d\n",a);
		printf("e:%d\n",e);
		printf("i:%d\n",i);
		printf("o:%d\n",o);
		printf("u:%d\n",u);
		if(n!=0)
			printf("\n");
		}
	}
	return 0;
}