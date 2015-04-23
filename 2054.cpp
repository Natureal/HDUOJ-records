////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 20:34:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2054
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
# include <stdio.h>
# include <string.h>
char *norm(char *a)
{
	int i,j;
	int len=strlen(a);
	if(strchr(a,'.')!=NULL)
	{
		while(a[--len]=='0');
            if(a[len]=='.')
                len--;
            a[len+1]='\0';
	}
	len=strlen(a);
	while(a[0]=='0')
	{
		for(j=0;j<len-1;j++)
			a[j]=a[j+1];
		a[len-1]='\0';
		len--;
	}
	return a;
}
int main()
{
    char a[12001],b[12001];
	while(scanf("%s%s",a,b)!=EOF)
	{
		if(!strcmp(norm(a),norm(b)))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}