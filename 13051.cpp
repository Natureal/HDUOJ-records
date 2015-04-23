////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-12 17:19:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1305
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1305.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月12日 星期三 16时05分42秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 5
typedef struct Trie
{
	Trie *next[MAX];
	int v;
}Trie;
Trie *root;
void Insert(char *str)
{
	int len=strlen(str);
	Trie *p=root,*q;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(p->next[id]==NULL)
		{
		    q=(Trie *)malloc(sizeof(Trie));
		    for(int j=0;j<MAX;j++)
		    {
		        q->next[j]=NULL;
		    }
		    q->v=0;
		    p->next[id]=q;
		    p=p->next[id];
		}
		else
		{
		    p=p->next[id];
		}
	}
	p->v=-1;
	return;
}
int findTrie(char *str)
{
    Trie *p=root;
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'0';
        p=p->next[id];
        if(p==NULL)
        {
            return 1;
        }
        if(p->v==-1)
        {
            return 0;
        }
    }
    return 0;
}
void dealTrie(Trie *T)
{
    if(T==NULL)
    {
        return;
    }
    for(int i=0;i<MAX;i++)
    {
        if(T->next[i]!=NULL)
        {
            dealTrie(T->next[i]);
        }
    }
    free(T);
    return;
}
int main()
{
    char s[20];
    int flag,t=0;
    root=(Trie *)malloc(sizeof(Trie));
    for(int i=0;i<MAX;i++)
    {
        root->next[i]=NULL;
    }
    flag=1;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='9')
        {
            t++;
            dealTrie(root);
            if(flag)
            {
                printf("Set %d is immediately decodable\n",t);
            }
            else
            {
                printf("Set %d is not immediately decodable\n",t);
            }
            root=(Trie *)malloc(sizeof(Trie));
            for(int i=0;i<MAX;i++)
            {
                root->next[i]=NULL;
            }
            flag=1;
            continue;
        }
        if(!findTrie(s))
        {
            flag=0;
        }
        Insert(s);
    }
    return 0;
}
