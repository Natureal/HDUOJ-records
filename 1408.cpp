////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-28 22:29:41
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1408
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	double v,d;
	int t,i;
	while(scanf("%lf %lf",&v,&d)!=EOF)
	{
		t=v/d;
		if(t!=v/d)
			t++;
		for(i=1;i<t;i++)
		{
			if((i+1)*i/2>=t)
			{
				break;
			}
		}
		i--;
		printf("%d\n",t+i);
	}
	return 0;
}