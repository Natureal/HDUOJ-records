////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-18 13:57:37
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2056
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	float x1,y1,x2,y2,x3,y3,x4,y4,k;
	float w,h,s;
	while(scanf("%f %f %f %f %f %f %f %f",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
	{
		k = x1 + x2;
		x2 = x2 > x1 ? x2:x1;
		x1 = k - x2;

		k= y1 + y2;
		y2 = y2 > y1 ? y2:y1;
		y1 = k - y2;

		k = x3 + x4;
		x4 = x4 > x3 ? x4:x3;
		x3 = k - x4;

		k = y3 + y4;
		y4 = y4 > y3 ? y4:y3;
		y3 = k - y4;

		if(y2>=y4 && y4>y1)
		{
			if(y1>=y3)
				h=y4-y1;
			else
				h=y4-y3;
		}
		else if(y2<y4 && y2>y3)
		{
			if(y3>=y1)
				h=y2-y3;
			else
				h=y2-y1;
		}
		else
			h=0;
		if(x3>=x1 && x2>x3)
		{
			if(x4>=x2)
				w=x2-x3;
			else
				w=x4-x3;
		}
		else if(x3<x1 && x4>x1)
		{
			if(x2>=x4)
				w=x4-x1;
			else
				w=x2-x1;
		}
		else
			w=0;
		s=w*h;
		printf("%.2f\n",s);
	}
	return 0;
}