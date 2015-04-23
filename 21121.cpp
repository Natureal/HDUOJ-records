////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 17:12:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2112
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:356KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define INF 100000000
int n,count;
int used[155],map[155][155],dis[155];
void Dijkstra()
{
	int k;
	for(int i=0;i<count;i++)
	{	
		dis[i]=map[0][i];
		used[i]=0;
	}
	used[0]=1;
	dis[0]=0;
	for(int i=0;i<count;i++)
	{
		int tmin=INF;
		for(int j=0;j<count;j++)
		{
			if(!used[j]&&tmin>dis[j])
			{
				tmin=dis[j];
				k=j;
			}
		}
		if(tmin==INF)break;
		used[k]=1;
		for(int j=0;j<count;j++)
		{
			if(!used[j] && dis[k]+map[k][j]<dis[j])
			{
				dis[j]=dis[k]+map[k][j];
			}
		}
	}
	if(dis[1]>=INF)
	{
		printf("-1\n");
	}
	else printf("%d\n",dis[1]);
	return;
}
int main()
{
	int i,j,a,b,c;
	char name[155][35],tname1[35],tname2[35];
	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		for(i=0;i<155;i++)
			for(j=0;j<155;j++)
				map[i][j]=INF;
		scanf("%s%s",name[0],name[1]);
		count=2;
		for(i=0;i<n;i++)
		{
			scanf("%s%s%d",tname1,tname2,&c);
			for(j=0;j<count;j++)
			{
				if(strcmp(tname1,name[j])==0)
				{
					a=j;
					break;
				}
			}
			if(j>=count)
			{
				a=count;
				strcpy(name[count++],tname1);
			}
			for(j=0;j<count;j++)
			{
				if(strcmp(tname2,name[j])==0)
				{
					b=j;
					break;
				}
			}
			if(j>=count)
			{
				b=count;
				strcpy(name[count++],tname2);
			}
			if(map[a][b]>c)
			{
			   map[a][b]=c;
			}
			if(map[b][a]>c)
			{
				map[b][a]=c;
			}
		}
		if(strcmp(name[0],name[1])==0)
		{
			printf("0\n");
		}
		else Dijkstra();
	}
	return 0;
}