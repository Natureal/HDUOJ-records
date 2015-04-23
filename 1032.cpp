////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-19 14:14:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1032
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int cal(int x)
{
	int sum=1;
	while(x!=1)
	{
		if(x%2)
			x=3*x+1;
		else
			x/=2;
		sum++;
	}
	return sum;
}
int main()
{
	int a,b,temp,max;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("%d %d ",a,b);
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		max=0;
		for(int j=a;j<=b;j++)
		{
			temp=cal(j);
			max=max>temp?max:temp;
		}
		printf("%d\n",max);
	}
	return 0;
}