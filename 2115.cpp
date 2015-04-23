////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 15:58:45
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2115
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
void sort(char name[][50],int s[][2],int n)
{
	int i,j,k,temp;
	char t[50];
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(s[j][0]<s[k][0])
				k=j;
			else if(s[j][0]==s[k][0])
			{
				if(strcmp(name[j],name[k])<0)
					k=j;
			}
		}
		if(k!=i)
		{
			temp=s[i][0];
			s[i][0]=s[k][0];
			s[k][0]=temp;

			strcpy(t,name[i]);
			strcpy(name[i],name[k]);
			strcpy(name[k],t);
		}
	}
	return;
}
int main()
{
	char name[10][50];
	int s[10][2],i,n,count=0;
	while(scanf("%d",&n)!=EOF && n)
	{
		count++;
		for(i=0;i<n;i++)
		{
			scanf("%s %d:%d",name[i],&s[i][0],&s[i][1]);
			s[i][0]=s[i][0]*60+s[i][1];
		}
		sort(name,s,n);
		if(count!=1)
		{
			puts("");
		}
		printf("Case #%d\n",count);
		for(i=0;i<n;i++)
		{
			if(i!=0 && s[i][0]==s[i-1][0])
			{
				printf("%s %d\n",name[i],i);
			}
			else
			{
				printf("%s %d\n",name[i],i+1);
			}
		}
	}
	return 0;
}