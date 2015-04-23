////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-20 20:28:55
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1070
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a,b,d,i,bx[101],cx[101],ex[101];
	double dx[101],min;
	char ax[101][101];
	scanf("%d",&a);
	while(a--)
	{
		scanf("%d",&b);
			for(i=0;i<b;i++)
			{
				scanf("%s%d%d",&ax[i],&bx[i],&cx[i]);
				if(cx[i]<200)
				{
					i--;//相当于忽略cx[i]<200这一情况
					b--;
				}
				else if(cx[i]>1000)
				{
					dx[i]=bx[i]/5.0;
				}
				else
				{
					ex[i]=cx[i]/200;
					dx[i]=bx[i]/(ex[i]*1.0);
				}
			}
			min=dx[0];
			d=0;
			for(i=1;i<b;i++)
			{
				if(min>dx[i])
				{
					min=dx[i];
					d=i;//记录性价比最高时的i值
				}
				else if(min==dx[i])
				{
					if(cx[d]<cx[i])
					{
						min=dx[i];
						d=i;
					}
				}
			}
			printf("%s\n",ax[d]);
	}
	return 0;
}