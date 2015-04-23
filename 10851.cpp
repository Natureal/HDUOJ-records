////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-25 23:46:19
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1085
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:856KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int i,j,k,c1[80000],c2[80000],b[4],sum;
int val[4]={0,1,2,5};
int main()
{
	//b数组存放1，2，5面值硬币的个数
	while(scanf("%d %d %d",&b[1],&b[2],&b[3])!=EOF)
	{
		if(b[1]==0 && b[2]==0 && b[3]==0) break;
		sum=0;
		for(i=1;i<=3;i++)
		{
			sum+=val[i]*b[i];
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0;i<=b[1];i++)
		{
			c1[i]=1;
		}
		for(i=2;i<=3;i++)//总共有三个表达式
		{
			for(j=0;j<=sum;j++)
			//j一直取到最高指数sum,若没有下一组，j就是遍历最终表达式的那个值
			{
				for(k=0;k+j<=sum && k<=b[i]*val[i];k+=val[i])//当k表示个数时，要全面变形
				{
					c2[j+k]+=c1[j];
				}
			}
			//从此处的更新遍历也能看出上句注释的含义！
			for(j=0;j<=sum;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		for(j=1;j<=sum+1;j++)//既然j以作为灵活的暂量，就一直用吧！
		{
			if(c1[j]==0)
			{
				printf("%d\n",j);//要注意是输出j（结果数）还是c1[j]（方案数）
				break;
			}
		}
	}
	return 0;
}