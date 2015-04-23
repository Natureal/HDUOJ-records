////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-24 00:02:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1736
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include<iostream>  
#include<cstring>  
#include<string>  
#include<cmath>  
using namespace std;  
  
typedef long long LL;  
const int N=201000;  
  
char s[N];  
  
int main()  
{  
    int i,j,T,t,n,m,a,b,sum;  
    while(gets(s)!=NULL)  
    {  
        int len=strlen(s);  
        sum=0;  
        for(i=0;i<len;i++)  
        {  
            string temp="";  
            temp=temp+s[i]+s[i+1];//这个地方用C语言怎么写呢，看到的人能说下么
            if(temp=="“"||temp=="”")
            {  
                sum++;  
            }  
            if(s[i]=='"')  
            {  
                if(sum%2==0)  
                    printf("“");  
                else  
                    printf("”");  
                sum++;  
  
            }  
            else if(s[i]==',')  
                printf("，");  
            else if(s[i]=='.')  
                printf("。");  
            else if(s[i]=='!')  
                printf("！");  
            else if(s[i]=='?')  
                printf("？");  
            else if(s[i]=='<'&&s[i+1]=='<')  
            {  
                i++;  
                printf("《");  
            }  
            else if(s[i]=='>'&&s[i+1]=='>')  
            {  
                i++;  
                printf("》");  
            }  
            else  
                printf("%c",s[i]);  
        }  
        printf("\n");  
    }  
    return 0;  
}