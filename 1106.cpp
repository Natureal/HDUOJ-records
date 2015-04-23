////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-14 19:52:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1106
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
void qsort(int s[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r,x=s[l];
		while(i<j)
		{
			while(i<j && s[j]>=x)
				j--;
			if(i<j)s[i++]=s[j];
			while(i<j && s[i]<x)
				i++;
			if(i<j)s[j--]=s[i];
		}
		s[i]=x;  
		qsort(s,l,i-1);
		qsort(s,i+1,r);
	}
}
int normal(char arr[],int n)
{
	int i;
	int number=0,flag=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]!='0') flag=1;
		if(flag)
		{
			number*=10;
			number+=arr[i]-'0';
		}
	}
	return number;
}
int main()
{
	int i,j,l,flag,k;
	int num[1005];
	char string[1005],str[1005];
	while(scanf("%s",string)!=EOF)
	{
		j=0;
		k=0;
		l=strlen(string);
		for(i=0;i<l;i++)
		{
			if(string[i]=='5')
			{
				flag=0;
				if(i==0||string[i-1]=='5')continue;
			}
			else
			{
				flag=1;
			}
			if(flag==1)
			{
				str[j++]=string[i];
			}
			if(flag==0 || i==l-1)
			{
				num[k++]=normal(str,j);
				j=0;
				memset(str,0,sizeof(str));
			}
		}
		qsort(num,0,k-1);
		for(i=0;i<k-1;i++)
		{
			printf("%d ",num[i]);
		}
		printf("%d\n",num[k-1]);
	}
	return 0;
}