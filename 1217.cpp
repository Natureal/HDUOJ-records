////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-17 22:06:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1217
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define INF 1000000
char name[35][30];
int n,m,count,t;
double map[35][35];
void Floyd()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(map[i][j]<map[i][k]*map[k][j])
				{
					map[i][j]=map[i][k]*map[k][j];
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(map[i][i]>1)
		{
			printf("Case %d: Yes\n",t);
			return;
		}
	}
	printf("Case %d: No\n",t);
	return;
}
void init()
{
	memset(map,0,sizeof(map));
	//for(int i=0;i<n;i++)
	//{
	//	for(int j=0;j<n;j++)
	//	{
	//		map[i][j]=INF;
	//	}
	//	map[i][i]=0;
	//}
	return;
}
int main()
{
	t=1;
	int a,b;
	double r;
	char temp1[30],temp2[30];
	while(scanf("%d",&n)!=EOF && n)
	{
		init();
		count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s",name[count++]);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%s%lf%s",temp1,&r,temp2);
			for(int j=0;j<count;j++)
				if(strcmp(temp1,name[j])==0)
				{
					a=j;
					break;
				}
			for(int j=0;j<count;j++)
				if(strcmp(temp2,name[j])==0)
				{
					b=j;
					break;
				}
			map[a][b]=r;
		}
		Floyd();
		t++;
	}
	return 0;
}