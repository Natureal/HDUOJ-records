////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-21 20:45:09
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1002
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#include<string.h>
int main()
{
    int a[1002]={0},b[1002]={0},c[1002]={0};
    int i,n,k,alen,blen,r=0;
    char str1[1002],str2[1002];
    scanf("%d",&n);
    while(n--)
    {
        if(r>0) printf("\n");
        scanf("%s",str1);
        alen=strlen(str1);
        scanf("%s",str2);
        blen=strlen(str2);
        k=alen>blen?alen:blen;
        for(i=0;i<alen;i++)
            a[i]=str1[alen-i-1]-'0';
        for(i=0;i<blen;i++)
            b[i]=str2[blen-i-1]-'0';
        for(i=0;i<k;i++)
                  {
            c[i]=a[i]+b[i]+c[i];
            c[i+1]=c[i]/10;
            c[i]=c[i]%10;
        }
        if(c[i])
            k++;
        r++;
        printf("Case %d:\n",r);
        printf("%s + %s = ",str1,str2);
        for(i=k-1;i>=0;i--)
            printf("%d",c[i]);
        printf("\n");
        memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
    }
    return 0;
}