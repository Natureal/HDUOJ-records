////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 11:49:30
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1390
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int binary_conversion(int x,int a[]);
int main()
{
	int i,m,n,j,a[1024],l;
    scanf("%d",&m);
	for(i=0;i<m;i++)  //总体计数变量i在循环里面就不要动了，不妨再弄个计数变量j
	{
		scanf("%d",&n);
		l=binary_conversion(n,a);
		for(j=0;j<l-1;j++)
		{
			if(1==a[j])
			printf("%d ",j);
		}
			printf("%d\n",l-1);
	}
	return 0;
}
int binary_conversion(int x,int a[])
{
	int m,count;
	for(m=x,count=1;;count++)
	{
		a[count-1]=m%2;
		m=m/2;
		if(0==m)
			break;
	}
	return count;
}