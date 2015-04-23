////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-09 22:56:55
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1247
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:5996KB
//////////////////System Comment End//////////////////
    #include <string.h>  
    #include <stdlib.h>  
    #include <stdio.h>  
    #include <iostream>  
      
    using namespace std;  
      
    #define MAX 26  
      
    typedef struct Node{  
        int isStr;  
        struct Node *next[MAX];  
        Node():isStr(0){  
            memset(next, NULL, sizeof(next));  
        }  
        ~Node(){  
            for(int i = 0;i < MAX; ++i)  
                if(next[i] != NULL)  
                    delete next[i];  
        }  
    }TrieNode,*Trie;  
      
    Trie root;  
    char s[50001][MAX];  
      
    void Insert(char *s){  
        TrieNode *p = root;  
      
        while(*s){  
            if(p ->next[*s-'a'] == NULL){  
                p ->next[*s-'a'] = new TrieNode;  
            }  
            p = p ->next[*s-'a'];  
            s++;  
        }  
        p->isStr = 1;  
        return ;  
    }  
      
    int find(char *s){  
        TrieNode *p = root;  
        while(*s){  
            if(p->next[*s - 'a'] != NULL){  
                p = p->next[*s - 'a'];  
                s++;  
            }  
            else return 0;  
        }  
        return p->isStr;  
    }  
      
    int main() {  
        //freopen("f:\\in1.txt","r",stdin);  
        //freopen("f:\\out1.txt","w",stdout);  
      
        int num = 0, k, i, j, flag, len;  
        char s2[MAX];  
        root = new TrieNode;  
        while(~scanf("%s",s[num])){  
            Insert(s[num++]);  
        }  
        for(i = 0; i < num; i ++){  
            flag = 0,len = strlen(s[i]);  
            for(j = 0; j < len - 1; j ++){//len-1是因为你切西瓜一定要切在西瓜上。  
                for(k = 0; k <= j; k++){  
                    s2[k] = s[i][k];  
                }  
                s2[k] = '\0';  
                if(find(s2)){  
                    strcpy(s2,s[i] + k);  
                    if(find(s2)){  
                        puts(s[i]);  
                        break;  
                    }  
                }  
            }  
        }  
        delete root;  
    }  