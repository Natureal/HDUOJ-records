////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-14 23:41:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2669
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int r=exgcd(b,a%b,x,y);
	int t=x;
	x=y;
	y=t-(a/b)*y;
	return r;
}

bool linear_equation(int a,int b,int c,int &x,int &y)
{
	int d=exgcd(a,b,x,y);
	if(c%d)
		return false;
	int k=c/d;
	x*=k;
	y*=k;
	while(x<0)
	{
		x+=b/d;
		y-=a/d;
	}
	return true;
}
int main()
{
	int a,b,x,y;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(linear_equation(a,b,1,x,y))
			printf("%d %d\n",x,y);
		else
			printf("sorry\n");
	}
	return 0;
}