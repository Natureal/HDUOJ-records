////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 11:24:13
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2045
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i;
	double a[51];
	a[1]=3;
	a[2]=6;
	a[3]=6;
	/*
a[i]=分两种，
1): 前i-1首尾不同 个数刚好a[i-1]
2): 前i-1首尾相同 显然第一个与第i-2个颜色就不能相同了，个数刚好a[i-2]
但是此时最后一个可以取两种颜色。。。所以xxxxxxxxxxx2
！！！注意当n=3时，上面公式是不符合的！！
*/

	while(scanf("%d",&n)!=EOF)
	{
		for(i=4;i<=n;i++)  //这里可以直接for(i=4;i<51;i++)算出所有的a[],然后在输出中自取，这样更符合大规模数据应用
		{
			a[i]=2*a[i-2]+a[i-1];
		}
		printf("%.lf\n",a[n]);
	}
	return 0;
}