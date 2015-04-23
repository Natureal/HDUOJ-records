////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-15 00:23:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1576
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
int main()
{
	int t,n,B,x,y;
	//Bx-A/9973*9973=n;(由于有个负号，不好直接用公式！）
	//Bx-9973*y=n;
	//因为gcd(B,9973)=Bx1+9973y1=1;两边同乘n得B(nx1)-9973(-ny1)=1;
	//因此nx1=x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&B);
		int d=exgcd(B,9973,x,y);
		int k=n/d;
		x*=k;
		while(x<0)
		{
			x+=9973/d;
		}
		printf("%d\n",x%9973);
	}
	return 0;
}