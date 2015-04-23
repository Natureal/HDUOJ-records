////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-23 02:50:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1203
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:504KB
//////////////////System Comment End//////////////////
# include <iostream>
# include <string.h>
using namespace std;
double min(double x,double y)
{
	return x>y?y:x;
}

int main()
{
	int n,m,a[10005],i,j;
	double b[10005],c[10005];
	while((cin>>n>>m)&&(n||m))
	{
		for(i=0;i<m;i++)
		{
			cin>>a[i]>>b[i];
			b[i]=1.0-b[i];
		}
		for(i=0;i<=n;i++)
			c[i]=1;
		for(i=0;i<m;i++)
		{
			for(j=n;j>=a[i];j--)
			{
				c[j]=min(c[j],c[j-a[i]]*b[i]);
			}
		}
		printf("%.1f%%\n",(1-c[n])*100);
	}
	return 0;
}