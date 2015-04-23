////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-11 22:03:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1048
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int i,sign;
	char a[32]={"VWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char str1[15],str2[15],str3[15],strci[200];
	sign = 1;
	gets(str1);
	while(strcmp("START",str1) == 0 && sign)
	{
		gets(strci);
		for(i=0;;i++)
		{
			if(strci[i]!='\0')
			{
				if(strci[i]>=97 && strci[i]<=122)
				{
					strci[i]-=32;
				}
				if(strci[i] >=65 && strci[i]<=90)
				{
					strci[i]=a[strci[i]-65];
				}
			}
			else
				break;
		}
		if(strcmp(gets(str2),"END") == 0)
		{
			puts(strci);
			str1[0]='\0';
		}
		if(strcmp(gets(str3),"ENDOFINPUT") == 0)
			break;
		if(strcmp(str3,"START")==0)
		   strcpy(str1,str3);
	}
	return 0;
}
