////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-19 22:12:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1198
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include<stdio.h>
#define MAXLEN 2500
int bo[11][4]={{1,1,0,0},{1,0,1,0},{0,1,0,1},{0,0,1,1},{1,0,0,1},{0,1,1,0},{1,1,1,0},{1,1,0,1},{0,1,1,1},{1,0,1,1},{1,1,1,1}};
int Find(int fa[][2],int p)
{
    int r=p,q;
    while(r!=fa[r][0]) r=fa[r][0];
    while(p!=r)
    {
        q=fa[p][0];
        fa[p][0]=r;
        p=q;
    }
    return r;
}
int Union(int fa[][2],int u,int v)
{
    int s1=Find(fa,u),s2=Find(fa,v);
    if(s1!=s2)
    {
        fa[s1][0]=s2;
        return 1;
    }
    return 0;
}
int set_n(int fa[][2],int n)
{
    int x=0;
    while(n>=0)
    {
        if(fa[n][0]==n) x++;
        n--;
    }
    return x;
}
int main()
{
    int i,m,n,fa[MAXLEN][2];
    char x;
    while(1)
    {
        scanf("%d%d",&m,&n);
        if(m==-1&&n==-1) break;
        getchar();
        if(n==0) break;
        else
        {
            for(i=0;i<m*n;i++) fa[i][0]=i;
            for(i=0;i<m*n;i++)
            {
                scanf("%c",&x);
                fa[i][1]=x-'A';
                if(x=='\n') {i--;continue;}
                if(bo[fa[i][1]][0]&&i-n>=0&&bo[fa[i-n][1]][3])
                {
                    Union(fa,i,i-n);
                }
                if(bo[fa[i][1]][1]&&(i%n)&&bo[fa[i-1][1]][2])
                {
                    Union(fa,i,i-1);
                }
            }
            printf("%d\n",set_n(fa,m*n-1));
        }
    }
	return 0;
}