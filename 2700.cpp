////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-22 23:44:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2700
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int num,i,len;
	char a[35];
	while(scanf("%s",a)!=EOF && a[0]!='#')
	{
		num=0;
		len=strlen(a);
		for(i=0;i<len-1;i++)
		{
			if(a[i]=='1')num++;
		}
		num=num%2;
		if(a[len-1]=='e')
		{
			if(num)a[len-1]='1';
			else a[len-1]='0';
		}
		else
		{
			if(num)a[len-1]='0';
			else a[len-1]='1';
		}
		printf("%s\n",a);
	}
	return 0;
}
	