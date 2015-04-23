////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-10 15:40:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1671
////Problem Title: 
////Run result: Accept
////Run time:359MS
////Run memory:3428KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1671.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月10日 星期一 15时12分01秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 10
typedef struct Trie
{
	struct Trie *next[MAX];
	int v;
}Trie;
Trie *root;
void createTrie(char *str)
{
	Trie *p=root,*q;
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'0';
		if(p->next[id]==NULL)
		{
			q=(Trie *)malloc(sizeof(Trie));
			for(int j=0;j<MAX;j++)
				q->next[j]=NULL;
			q->v=1;
			p->next[id]=q;
			p=p->next[id];
		}
		else
		{
			p=p->next[id];
			p->v++;
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
			return 0;
		}
		if(p->v==-1)
		{
			return 1;
		}
	}
	return 1;
}
void dealTrie(Trie *T)
{
	if(T==NULL)
		return;
	for(int i=0;i<MAX;i++)
	{
		if(T->next[i]!=NULL)//儿子不是全都空
		{
			dealTrie(T->next[i]);
		}
	}
	free(T);//当儿子都空了以后，free自己！
	return;
}
int main()
{
	int t,n,flag;
	char s[10001][11];
	scanf("%d",&t);
	while(t--)
	{
		root=(Trie *)malloc(sizeof(Trie));
		for(int i=0;i<MAX;i++)
		{
			root->next[i]=NULL;
		}
		flag=1;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s[i]);
			if(findTrie(s[i]))
				flag=0;
			createTrie(s[i]);
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
		dealTrie(root);
	}
	return 0;
}
