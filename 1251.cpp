////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-09 21:50:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1251
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:43880KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1251.cpp
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月09日 星期日 20时19分37秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAX 26
struct Trie
{
	struct Trie *next[MAX];
	int v;
};

struct Trie *root;
void createTrie(char *str)
{
	int len=strlen(str);
	struct Trie *p=root,*q;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';
	//	printf("%d\n",id);
		if(p->next[id]==NULL)
		{
			q=(struct Trie *)malloc(sizeof(struct Trie));
			for(int j=0;j<MAX;j++)
			{
				q->next[j]=NULL;
			}
			p->next[id]=q;
			p=p->next[id];
			p->v=1;
		}
		else
		{
			p=p->next[id];
			p->v++;
		}
	}
	return;
}
int findTrie(char *str)
{
	int len=strlen(str);
	struct Trie *p=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';
		if(p->next[id]!=NULL)
			p=p->next[id];
		else
			return 0;
	}
	return p->v;
}
int dealTrie(struct Trie *T)
{
	int i;
	if(T==NULL)
		return 0;
	for(int i=0;i<MAX;i++)
	{
		if(T->next[i]!=NULL)
			dealTrie(T->next[i]);
	}
	free(T);
	return 0;
}
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
	char arr[11];
	root=(Trie *)malloc(sizeof(struct Trie));
	for(int i=0;i<MAX;i++)
	{
		root->next[i]=NULL;
	}
	while(gets(arr)&&arr[0]!='\0')
	{
		createTrie(arr);
	}
	while(gets(arr))
	{
		printf("%d\n",findTrie(arr));
	}
//	dealTrie(root);
	return 0;
}