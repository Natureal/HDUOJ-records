////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-04 21:18:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5199
////Problem Title: 
////Run result: Accept
////Run time:1279MS
////Run memory:44944KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

#define maxn 1000009
#define MOD 10000009

int head[MOD+10],nex[maxn],a[maxn];
int point[maxn],now=0,sum[maxn],v[maxn];
int n,m;
void add(int x,int y){
    nex[++now]=head[x];
    head[x]=now;
    point[now]=y;
    v[now] = 1;
}
void insert(int x){
    int u=x%MOD;if(u<0)u*=-1;
    for(int i=head[u];i;i=nex[i])
    {
        if(point[i]==x){
            v[i]++;
            return;
        }
    }
    add(u,x);
}
int find(int x){
    int u=x%MOD;if(u<0)u*=-1;
    for(int i=head[u];i;i=nex[i]){
        if(point[i]==x){
            int cur = v[i];
            v[i] = 0;
            return cur;
        }
    }
    return 0;
}
int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int main(){
    int a;
    while(scanf("%d%d",&n,&m) != EOF){
        now = 0;
        MEM(head,0);
        MEM(v,0);
        for(int i = 1; i <= n; ++i){
            a = read();
            insert(a);
        }
        for(int i = 1; i <= m; ++i){
            a = read();
            printf("%d\n",find(a));
        }
    }
    return 0;
}