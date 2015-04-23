////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-18 14:44:17
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2073
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
struct POINT
{
	int x;
	int y;
};
int main()
{
	int i,t,k;
	double len;
	struct POINT a,b,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
		len=0;
		if(a.x+a.y==b.x+b.y)
		{
			len=sqrt(1.0*(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
		}
		else
		{
			if(a.x+a.y>b.x+b.y)
			{
				c=a;
				a=b;
				b=c;
			}
			len+=a.y*sqrt(2.0);
			len+=b.x*sqrt(2.0);
			k=b.x+b.y;
			for(i=a.x+a.y;i<k;i++)
			{
				len+=sqrt(1.0*i*i+(i+1)*(i+1));
			}
			for(i=a.x+a.y+1;i<k;i++)
			{
				len+=i*sqrt(2.0);
			}
		}
		printf("%.3lf\n",len);
	}
	return 0;
}