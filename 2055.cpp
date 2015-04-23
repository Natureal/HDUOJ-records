////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 21:52:20
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2055
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,y,x1;
	char x;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		scanf("%c %d",&x,&y);
		getchar();
		if(x>='a'&&x<='z')
		{
			x1=-(x-96);
		}
		if(x>='A'&&x<='Z')
		{
			x1=x-64;
		}
		printf("%d\n",x1+y);
	}
	return 0;
}