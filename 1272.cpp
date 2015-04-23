////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-15 21:25:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1272
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:648KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int fa[100005];
int find(int x)
{
	if(fa[x]!=x)fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	int a,b,d1,d2,flag,count;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a==-1 && b==-1)
			break;
		else if(a==0 && b==0)
		{
			printf("Yes\n");
			continue;
		}
		else
		{
			d1=a;
			d2=b;
		}
		memset(fa,0,sizeof(fa));
		fa[d1]=d1;
		fa[d2]=d2;
		d1=find(d1);
		d2=find(d2);
		fa[d2]=d1;
		flag=1;
		while(scanf("%d%d",&a,&b)!=EOF && a||b)
		{
			d1=a;
			d2=b;
			if(fa[d1]==0)fa[d1]=d1;
			if(fa[d2]==0)fa[d2]=d2;
	     	d1=find(d1);
	    	d2=find(d2);
			if(d1==d2)
			{
				flag=0;
			}
			fa[d2]=d1;
		}
		count=0;
		for(int i=0;i<100005;i++)
		{
			if(!fa[i])continue;
			if(fa[i]==i)count++;
		}
		if(count>=2)flag=0;
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}