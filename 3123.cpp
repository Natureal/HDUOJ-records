////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-14 19:07:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3123
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int len,t,m,n,i;
    char s[105],temp[15];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%d",s,&m);
        len=strlen(s);
        if(len>=7)//额外判断
        {
            n=m-1;
        }
        else
        {
            memcpy(temp,s,len+1);
            sscanf(temp,"%d",&n);
            if(n>=m)
            {
                n=m-1;//重要的判断
            }
        }
        __int64 sum=1,mod=1;
        for(i=1;i<=n;i++)
        {
            mod=(mod*i)%m;
            sum=(sum+mod);
        }
        printf("%I64d\n",sum%m);
    }
    return 0;
}
