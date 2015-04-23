////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-09 23:30:59
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2030
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:208KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int n,count;
	char c;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();//吃掉row7中scanf中输入的'\n'，以防止'\n'作为文本第一个字符！
		while(n--)
		{
			count = 0;
			while((c = getchar())!='\n')
			{
				if(c < 0)
					count++;
			}
			printf("%d\n",count/2);
		}
	}
	return 0;
}