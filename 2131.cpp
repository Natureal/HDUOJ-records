////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-14 21:43:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2131
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
    char c,word[205];
    int i,len,count;
    while(scanf("%c",&c)!=EOF)
    {
		getchar();
        gets(word);
        len=strlen(word);
        count=0;
        for(i=0;i<len;i++)
        {
            if(c==word[i] || c==word[i]+32 || c+32==word[i])
                count++;
        }
        printf("%.5lf\n",(double)count/len);
    }
    return 0;
}