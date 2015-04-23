////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-19 17:44:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2594
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:764KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MAXN 50000

char s1[2 * MAXN + 5],s2[MAXN + 5];
int Next[2 * MAXN + 5];

void Getnext(char *p,int *next){
    int i = 0, j = -1,len = strlen(p);
    next[0] = -1;
    while(i != len - 1){
        if(j == -1 || p[i] == p[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else{
            j = next[j];
        }
        /*if(j == -1){
            ++i; ++j;
            next[i] = 0;
        }
        else if(p[i] == p[j]){
            ++i; ++j;
            next[i] = next[i - 1] + 1;
        }
        else{
            j = next[j];
        }*/
    }
}
void Debug(int l){
    for(int i = 0; i < l; i++){
        printf("next[ %d ] : %d\n",i,Next[i]);
    }
}
int main()
{
   //freopen("in","r",stdin);
    int len;
    memset(Next,0,sizeof(Next));
    memset(s1,'\0',sizeof(s1));
    memset(s2,'\0',sizeof(s2));
    while(scanf("%s",s1) != EOF){
        scanf("%s",s2);
        len = strlen(s1);
        s1[len] = 'A';
        strcat(s1,s2);
        len = strlen(s1);
        s1[len] = 'B';
        ++len;
        //printf("s : %s\n",s1);
        Getnext(s1,Next);
        //Debug(len);
        if(Next[len - 1] == 0){
            printf("0\n");
        }
        else{
            int l = Next[len - 1];
            for(int i = 0; i < l; i++){
                printf("%c",s1[i]);
            }
            printf(" %d\n",l);
        }
        memset(Next,0,sizeof(Next));
        memset(s1,'\0',sizeof(s1));
        memset(s2,'\0',sizeof(s2));
    }
    return 0;
}
