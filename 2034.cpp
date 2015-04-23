////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-10 19:32:17
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2034
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define N 100
int main()
{
	void sort(int x[N],int l);
	int n,m,i,j,a[N],b[N],c[N],k;
	while(scanf("%d %d",&n,&m)!=EOF && (m||n))
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&b[i]);
		}
		for(i=0,k=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i] == b[j])
				{
					break;
				}
			}
			if(j>=m)
			{
				c[k++]=a[i];
			}
		}
		if(k)
		{
			sort(c,k);
			for(i=0;i<k;i++)
			{
				printf("%d ",c[i]);
			}
		}
		else
			printf("NULL");
		printf("\n");
	}
	return 0;
}

//void sort(int x[N],int l)
//{
//	int i,j,mark,temp;
//	for(i=0;i<l-1;i++)
//	{
//		mark = i;
//		for(j=i+1;j<l;j++)
//		{
//			if(x[j] < x[i])
//			{
//				mark = j;
//			}
//		}
//		if( mark != i)  //这里切记要判断！
//		{
//		   temp = x[i];//切记x[mark]为较小值！
//		   x[i] = x[mark];
//		   x[mark] = temp;
//		}
//	}
//	return;
//}
void sort(int a[N],int l)
{
	int t,i,j;
	for(i=0;i<l-1;i++)
	{
		for(j=0;j<l-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	return;
}