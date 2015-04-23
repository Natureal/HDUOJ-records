////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-13 22:23:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1202
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n;
	double sum,sum2,s,p;
	while(scanf("%d",&n)!=EOF)
	{
		sum=sum2=0;
		while(n--)
		{
			scanf("%lf%lf",&s,&p);
			if(p==-1)continue;
			else if(p>=90)
			{
				sum+=s*4;
			}
			else if(p>=80)
			{
				sum+=s*3;
			}
			else if(p>=70)
			{
				sum+=s*2;
			}
			else if(p>=60)
			{
				sum+=s;
			}
			sum2+=s;
		}
	if(sum2 == 0)
		printf("-1\n");
	else
    printf("%.2lf\n",sum/sum2);
	}
	return 0;
}