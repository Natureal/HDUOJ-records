////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-12 22:24:11
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2086
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	 double a,b,c[3001],k;
	 int n,i;
	 while(scanf("%d",&n)!=EOF)
	 {
		 scanf("%lf%lf",&a,&b);
		 for(i=1;i<=n;i++)
		 {
			 scanf("%lf",&c[i]);
		 }
		 k=0;
		 for(i=1;i<=n;i++)
		 {
			 k+=(n+1-i)*c[i];
		 }
		 printf("%.2lf\n",(1.0*n*a+b-2*k)/(1.0*n+1));
	 }
	 return 0;
}
