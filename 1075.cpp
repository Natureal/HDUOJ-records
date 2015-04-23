////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-12 15:02:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1075
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:69592KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
char s1[500010][15],s2[500010][15];
#define MAX 26
typedef struct Trie
{
    Trie *next[MAX];
    int v;
} Trie;
Trie *root;
void Insert(char *str,int num)
{
    int len=strlen(str);
    Trie *p=root,*q;
    for(int i=0; i<len; i++)
    {
        int id=str[i]-'a';
        if(p->next[id]==NULL)
        {
            q=(Trie *)malloc(sizeof(Trie));
            for(int j=0; j<MAX; j++)
            {
                q->next[j]=NULL;
            }
            q->v=-1;
            p->next[id]=q;
            p=p->next[id];
        }
        else
        {
            p=p->next[id];
        }
    }
    p->v=num;
}
int findTrie(char *str)
{
    int len=strlen(str);
    Trie *p=root;
    for(int i=0; i<len; i++)
    {
        if(str[i]<'a'||str[i]>'z')
            return -1;
        int id=str[i]-'a';
        p=p->next[id];
        if(p==NULL)
        {
            return -1;
        }
    }
    return p->v;
}
void dealTrie(Trie *T)
{
    if(T==NULL)
    {
        return;
    }
    for(int i=0; i<MAX; i++)
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
    //freopen("input.txt","r",stdin);
    int n=0;
    char a[30],st[30];
    root=(Trie *)malloc(sizeof(Trie));
    for(int i=0; i<MAX; i++)
    {
        root->next[i]=NULL;
    }
    gets(st);
    while(gets(a)&&strcmp(a,"END")!=0)
    {
        sscanf(a,"%s%s",s1[n],s2[n]);
        Insert(s2[n],n);
    //    printf("%s %s",s1[n],s2[n]);
        n++;
    }
    gets(st);
    char b[3005];
    while(gets(b)&&strcmp(b,"END")!=0)
    {
        char temp[30];
        int flag,count;
        int len=strlen(b);
        count=0;
        flag=0;
        for(int i=0; i<len; i++)
        {
            if(!flag && b[i]>='a'&&b[i]<='z')
            {
                flag=1;
            }
            else if(flag && (b[i]==' '||b[i]==','||b[i]=='.'))
            {
                temp[count]='\0';
                count=0;
                int m=findTrie(temp);
                if(m==-1)
                {
                    cout<<temp;
                }
                else
                {
                    cout<<s1[m];
                }
                cout<<b[i];
                flag=0;
            }
            else if(!flag && (b[i]<'a'||b[i]>'z'))
            {
                printf("%c",b[i]);
            }
            if(flag)
            {
                temp[count++]=b[i];
			}
		}
		if(flag)
		{
			temp[count]='\0';
			int m=findTrie(temp);
			if(m==-1)
			{
				cout<<temp;
			}
			else
			{
				cout<<s1[m];
			}
		}
		puts("");
    }
    dealTrie(root);
    return 0;
}
