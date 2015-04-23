////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-10 16:07:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1894
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:2144KB
//////////////////System Comment End//////////////////
#include<iostream>
#include<string>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iterator>
using namespace std;
int const maxn=500010;
 
char ch[maxn][33];
int tab[maxn];
bool mysort(int n,int n2){
    return strcmp(ch[n],ch[n2])<0;
}
bool isin(int n1,int n2){
    int n=strlen(ch[n1]);
    for(int i=0;i<n;i++)
        if(ch[n1][i]!=ch[n2][i])return 0;
    return 1;
}
int main()
{
   // freopen("1.txt","r",stdin);
    int t;
    cin>>t;
 
    while(t--){
        int c=0;
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%s",ch[i]),tab[i]=i;
        sort(tab,tab+n,mysort);
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isin(tab[i],tab[j]))++c;
                else break;
                if(c>11519)c%=11519;
            }
        }
        printf("%d\n",c);
    }
 
}