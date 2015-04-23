////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 13:15:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2079
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int c1[1000],c2[1000];
int main()
{
	//这题要注意防止字母混用！
	int i,j,c,n,m,k,s[10],num[10],t;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=m;i++)
		{
 			scanf("%d %d",&s[i],&num[i]);
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0;i<=num[1];i++)
		{
			c1[i*s[1]]=1;
		}
		t=s[1]*num[1];
		for(i=2;i<=m;i++)
		{
			for(j=0;j<=t;j++)
			{
				for(k=0;k<=s[i]*num[i];k+=s[i])
				{
					c2[j+k]+=c1[j];
				}
			}
			t+=s[i]*num[i];
			for(j=0;j<=t;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%d\n",c1[n]);
	}
	return 0;
}