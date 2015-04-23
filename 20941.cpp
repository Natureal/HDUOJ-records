////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 21:59:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2094
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,n,mark,sign;
	char a[1001][15],b[1001][15];
	while(scanf("%d",&n)!=EOF && n)
	{
		getchar();
		sign=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",a[i]);
			scanf("%s",b[i]);
		}
		for(i=0;i<n;i++)
		{
			mark=0;
			for(j=i-1;j>=0;j--)
			{
				if(strcmp(a[i],a[j])==0)
				{
					mark=1;
					break;
				}
			}
			if(mark==0)
			{
				for(j=0;j<n;j++)
				{
					if(strcmp(a[i],b[j])==0)
					{
						break;
					}
				}
				if(j>=n)
				{
					sign++;  //sign记录没有败绩的人的数量
				}
			}
		}
		if(sign==1)  //如果sign==1，有唯一冠军，如果sign〉1，无法判断
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
