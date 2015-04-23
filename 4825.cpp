////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-20 23:12:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4825
////Problem Title: 
////Run result: Accept
////Run time:703MS
////Run memory:41564KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#define LL long long
#define RA 32

typedef struct Trie{
    Trie *next[2];
    LL v;
};
Trie *root;

void Insert(int *str,LL num){
    Trie *p = root, *q;
    int id;
    for(int i = 0; i < RA; i++){
        id = str[i];
        if(p -> next[id] == NULL){
            q = (Trie *)malloc(sizeof(Trie));
            q -> next[0] = NULL;
            q -> next[1] = NULL;
            q -> v = 0;
            p -> next[id] = q;
           //printf("create %d\n",id);
        }
        p = p -> next[id];
           //printf("go to %d\n",id);
    }
    p -> v = num;
}
LL FindTrie(int *str){
    Trie *p = root;
    int id;
    for(int i = 0; i < RA; i++){
        id = str[i];
        if(p -> next[1 - id] != NULL){
            p = p -> next[1 - id];
        }
        else{
            p = p -> next[id];
        }
    }
    return p -> v;
}
void DealTrie(Trie *T){
    if(T == NULL)
        return;
    for(int i = 0; i < 2; i++){
        if(T -> next[i] != NULL)
            DealTrie(T -> next[i]);
    }
    free(T);
}
int main(){
    int str[32];
    int n,m,Case;
    LL tmp,num;
    while(scanf("%d",&Case) != EOF){
        for(int t = 1; t <= Case; t++){
            //init root
            root = (Trie *)malloc(sizeof(Trie));
            root -> next[0] = NULL;
            root -> next[1] = NULL;
            root -> v = 0;

            scanf("%d %d",&n,&m);
            for(int i = 0; i < n; i++){
                scanf("%I64d",&num);
                memset(str,0,sizeof(str));
                tmp = num;
                for(int i = RA - 1; i >= 0; i--){
                    str[i] = (tmp & 1);
                    tmp >>= 1;
                }
                Insert(str,num);
            }
            printf("Case #%d:\n",t);
            while(m--){
                scanf("%I64d",&num);
                memset(str,0,sizeof(str));
                tmp = num;
                for(int i = RA - 1; i >= 0; i--){
                    str[i] = (tmp & 1);
                    tmp >>= 1;
                }
            printf("%I64d\n",FindTrie(str));
            }
        }
        DealTrie(root);
    }

    return 0;
}
