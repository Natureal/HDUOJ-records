////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-22 22:14:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1690
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:368KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define INF  0x7fffffffffffff
__int64  d[125][125],p[125];
__int64 temp,l1,l2,l3,l4,c1,c2,c3,c4;
void Floyd(int n)
{
int i,j,k;
for(k=1;k<=n;k++)
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(d[i][k]!=INF && d[k][j]!=INF &&d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
}
int main()
{
int n,m,t,ti,i,j;
scanf("%d",&t);
for(ti=1;ti<=t;ti++)
{
scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&l1,&l2,&l3,&l4,&c1,&c2,&c3,&c4);
scanf("%d%d",&n,&m);
for(i=1;i<=n;i++)
{
 scanf("%I64d",&p[i]);
}
for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
		{
			temp=p[i]-p[j];
			if(temp<0)temp=-temp;
			
			if(temp==0) d[i][j]=d[j][i]=0;
			else if(temp<=l1)d[i][j]=d[j][i]=c1;
			else if(temp<=l2)d[i][j]=d[j][i]=c2;
			else if(temp<=l3)d[i][j]=d[j][i]=c3;
			else if(temp<=l4)d[i][j]=d[j][i]=c4;
			else d[i][j]=d[j][i]=INF;
		}
printf("Case %d:\n",ti);
Floyd(n);
int s,t;
for(i=1;i<=m;i++)
{
scanf("%d%d",&s,&t);
if(d[s][t]!=INF)
		printf("The minimum cost between station %d and station %d is %I64d.\n",s,t,d[s][t]);
else
		printf("Station %d and station %d are not attainable.\n",s,t);
}
}
return 0;
}