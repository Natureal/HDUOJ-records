////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-20 23:13:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4825
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:24524KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define LL long long
#define MAXN 3200000
#define RA 32

typedef struct Trie{
    int next[2];
    LL v;
}Trie;
Trie tr[MAXN + 10];

int node;
void Insert(int *str,LL num){
    int id,pos = 1;
    for(int i = 1; i <= RA; i++){
        id = str[i];
        if(tr[pos].next[id] == 0){
            tr[node].v = 0;
            tr[node].next[0] = tr[node].next[1] = 0;
            tr[pos].next[id] = node++;
        }
        pos = tr[pos].next[id];
    }
    tr[pos].v = num;
}LL FindTrie(int *str){
    int id,pos = 1;
    for(int i = 1; i <= RA; i++){
        id = str[i];
        if(tr[pos].next[1 - id]){
            pos = tr[pos].next[1 - id];
        }
        else{
            pos = tr[pos].next[id];
        }
    }
    return  tr[pos].v;
}
int main()
{
    int str[33];
    int n,m,Case;
    LL num,tmp;
    while(scanf("%d",&Case) != EOF){
        for(int t = 1; t <= Case; t++){
            node = 2;
            tr[1].v = 0;
            tr[1].next[0] = tr[1].next[1] = 0;
            scanf("%d %d",&n,&m);
            for(int i = 0; i < n; i++){
                scanf("%I64d",&num);
                memset(str,0,sizeof(str));
                tmp = num;
                for(int j = RA; tmp && j >= 1; j--){
                    str[j] = (tmp & 1);
                    tmp >>= 1;
                }
                Insert(str,num);
            }
            printf("Case #%d:\n",t);
            while(m--){
                scanf("%I64d",&num);
                memset(str,0,sizeof(str));
                tmp = num;
                for(int j = RA;tmp && j >= 1; j--){
                    str[j] = (tmp & 1);
                    tmp >>= 1;
                }
                printf("%I64d\n",FindTrie(str));
            }
        }
    }
    return 0;
}
