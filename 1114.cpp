////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-01 14:25:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1114
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
const int N=501,oo=1000000000;
int f[10001]={0},g[10001],p[N],w[N];
void main()
{ 
	int T,n,t,v,i,j;  
	scanf("%d",&T); 
	while (T--)
    {
		scanf("%d%d",&t,&v);
		for (i=1;i<=v;i++) f[i]=oo;
		v-=t;
        scanf("%d",&n);
		for (i=1;i<=n;i++) scanf("%d%d",&p[i],&w[i]);      
		for (i=1;i<=n;i++)
		for (j=w[i];j<=v;j++)
			if (f[j-w[i]]+p[i]<f[j]) f[j]=f[j-w[i]]+p[i];
			if (f[v]==oo) printf("This is impossible.\n");
			else printf("The minimum amount of money in the piggy-bank is %d.\n",f[v]);
	}
 }

