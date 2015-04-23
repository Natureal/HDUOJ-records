////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-16 14:35:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1161
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int l;
	char str[1005];
	while(gets(str)!=NULL)
	{
		l=strlen(str);
		for(int i=0;i<l;i++)
		{
			if(str[i]>='A' && str[i]<='Z')
			{
				str[i]+=('a'-'A');
			}
		}
		printf("%s\n",str);
	}
	return 0;
}