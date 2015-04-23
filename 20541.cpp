////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 20:58:19
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:616KB
//////////////////System Comment End//////////////////
# include <stdio.h>
# include <string.h>
int sign;
char *norm(char *a)
{
	int i,j;
	int len=strlen(a);
	if(a[0]=='-')
	{
		for(i=0;i<len-1;i++)
		{
			a[i]=a[i+1];
		}
		a[--len]='\0';
		sign=0;
	}
	else
		sign=1;
	if(strchr(a,'.')!=NULL)
	{
		while(a[--len]=='0');
            if(a[len]=='.')
                len--;
            a[len+1]='\0';
	}
	len=strlen(a);
	while(a[0]=='0'&& len>1)
	{
		for(j=0;j<len-1;j++)
			a[j]=a[j+1];
		a[len-1]='\0';
		len--;
	}
	if(len==1 && a[0]=='0')
	{
		a[1]='\0';
		sign=1;
	}
	return a;
}
int main()
{
    char a[100000],b[100000],c[100000],d[100000],sign1,sign2;
	while(scanf("%s%s",a,b)!=EOF)
	{
		strcpy(c,norm(a));
		sign1=sign;
		strcpy(d,norm(b));
		sign2=sign;
		if(!strcmp(c,d) && sign1==sign2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}