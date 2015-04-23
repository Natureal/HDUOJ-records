////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-13 21:56:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1009
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,n,a[1000][2],j,k;
	double b[1000],m,sum,temp;
	while(scanf("%lf %d",&m,&n)!=EOF && !(m==-1 && n==-1))
	{
		sum=0;
		for(i=0;i<n;i++)
		{
 			scanf("%d %d",&a[i][0],&a[i][1]);
			b[i]=(double)a[i][0]/a[i][1];
		}
		for(i=0;i<n-1;i++)
		{
			k=i;
			for(j=i+1;j<n;j++)
			{
				if(b[j]>b[k])
					k=j;
			}
			if(k!=i)
			{
				temp=b[i];
				b[i]=b[k];
				b[k]=temp;
				temp=a[i][0];
				a[i][0]=a[k][0];
				a[k][0]=temp;
				temp=a[i][1];
				a[i][1]=a[k][1];
				a[k][1]=temp;
			}
		}
		for(i=0;i<n;i++)
		{
			if(m>=a[i][1])
			{
				sum+=a[i][0];
				m-=a[i][1];
			}
			else if(m>0 && m<a[i][0])
			{
				sum+=1.0*m*a[i][0]/a[i][1];
				m-=a[i][1];
			}
			else if(m<=0)
			    break;
		}
		printf("%.3lf\n",sum);
	}
	return 0;
}