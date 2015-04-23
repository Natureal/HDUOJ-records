////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-18 15:38:08
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2072
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:512KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,num,len,l,mark,word,flag;
	char a[300][1000],b[1000];
	while(gets(b)!=NULL && b[0]!='#')
	{
		len=strlen(b);
		num=0;
		word=l=0;
		flag=0;
		memset(a,'\0',sizeof(a));
		for(i=0;i<len;i++)
		{
			if(b[i]==' ')
			{
				if(b[i+1]==' ') continue;
				else if(b[i+1]=='\0') break;
				else
				{
					num++;
					l=0;
				}
			}
			else
			{
				a[num][l]=b[i];
				l++;
				flag=1;
			}
		}
		for(i=0;i<num;i++)
		{
			mark=1;
			for(j=i+1;j<=num;j++)
			{
				if(strcmp(a[i],a[j])==0)
				{
					mark=0;
					break;
				}
			}
			if(mark) word++;
		}
		printf("%d\n",flag?word+1:word);
	}
	return 0;
}