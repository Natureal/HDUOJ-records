////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-07 17:12:43
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1266
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int t,n1,n2,i;
	char a[100000],temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",a);
		n1=0;
		if(a[0]=='-')
			n1=1;
		for(i=strlen(a)-1;i>0;i--)
		{
			if(a[i]!='0')
			{
				break;
			}
		}
		n2=i;
		for(i=n1;i<=(n1+n2)/2;i++)
		{
			temp=a[i];
			a[i]=a[n1+n2-i];
			a[n1+n2-i]=temp;
		}
		printf("%s\n",a);
	}
	return 0;
}