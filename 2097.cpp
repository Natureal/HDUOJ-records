////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-12 22:40:42
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2097
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
char *tra(int n,int b,char *a)
//n为十进制数，b为想要转换到的进制数
{
	char temp;
	int k,r,i,j;
	k=n;
	i=0;
	while(k)
	{
		r=k%b;
		if(r>=0 && r<=9)
		{
			*(a+i)=r+'0';
			i++;
		}
		else if(r>=10)
		{
			*(a+i)=r-10+'A';
			i++;
		}
		k/=b;
	}
	i--;
	for(j=0;j<=i/2;j++)
	{
		temp=*(a+j);
		*(a+j)=*(a+i-j);
		*(a+i-j)=temp;
	}
	*(a+i+1)='\0';
	return a;
}

int cal(char *a)
{
	int i,sum=0;
	for(i=0;i<strlen(a);i++)
	{
		if(*(a+i)>='0' && *(a+i)<='9')
			sum+=*(a+i)-'0';
		else if(*(a+i)>='A' && *(a+i)<='Z')
			sum+=*(a+i)-'A'+10;
	}
	return sum;
}
int main()
{
	int n,k;
	char c[10];
	while(scanf("%d",&n)!=EOF && n)
	{
		k=n/1000+n%1000/100+n%100/10+n%10;
		if(k==cal(tra(n,16,c)))
		{
			if(k==cal(tra(n,12,c)))
			{
				printf("%d is a Sky Number.\n",n);
			}
			else
			{
				printf("%d is not a Sky Number.\n",n);
			}
		}
		else
		{
			printf("%d is not a Sky Number.\n",n);
		}
	}
	return 0;
}