////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-17 22:26:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1201
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int judge(int y)
{
	if((y%100==0&&y%400==0)||(y%100!=0&&y%4==0))
		return 1;
	return 0;
}
int main()
{
	int t,y,m,d,y2,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d-%d-%d",&y,&m,&d);
		y2=y+18;
		if(m==2&&d==29&&!judge(y2))
		{
			printf("-1\n");
			continue;
		}
		sum=0;
		if(judge(y)&&m<3)sum++;
		if(judge(y2)&&m>2)sum++;
		for(int i=y+1;i<y2;i++)
		{
			if(judge(i))
				sum++;
		}
		printf("%d\n",365*18+sum);
	}
	return 0;
}