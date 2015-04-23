////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 21:58:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2094
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,num,n,flag,k;
	char str1[1001][15],str2[1001][15];
	while(scanf("%d",&n)&&n!=0)
	{
		num=0;
		getchar();
		for(i=0;i<n;i++)
		{
			scanf("%s",str1[i]);
			scanf("%s",str2[i]);
		}
		for(i=0;i<n;i++)
		{
			flag=0;
			for(k=i-1;k>=0;k--)
				if(strcmp(str1[k],str1[i])==0)
				{
					flag=1;
					break;
				}
			if(flag==0)   
			{
				for(j=0;j<n;j++)
				{
					if(strcmp(str1[i],str2[j])==0)
						break;
				}
			if(j>=n)num++;
			}
		}
			if(num==1)printf("Yes\n");
			else printf("No\n");
	}
	return 0;
}