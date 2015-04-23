////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-05 22:14:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5199
////Problem Title: 
////Run result: Accept
////Run time:1029MS
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
#define maxn 1000009
#define mod 10000009

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int head[mod + 10],nex[maxn],a[maxn];
int point[maxn],now=0,sum[maxn];
int cnt[maxn];
int n,m;

void Add(int x,int y){
    nex[++now] = head[x];
    point[now] = y;
    cnt[now] = 1;
    head[x] = now;
}

void Insert(int x){
    int u = abs(x % mod);
    for(int i=head[u];i;i=nex[i]) if(point[i]==x){
        cnt[i]++;
        return;
    }
    Add(u,x);
}

int Find(int x){
    int u = abs(x % mod);
    for(int i=head[u];i;i=nex[i]) if(point[i]==x){
        int cur = cnt[i];
        cnt[i] = 0;
        return cur;
    }
    return 0;
}

int Read(){
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
        MEM(cnt,0);
        for(int i = 1; i <= n; ++i){
            a = Read();
            Insert(a);
        }
        for(int i = 1; i <= m; ++i){
            a = Read();
            printf("%d\n",Find(a));
        }
    }
    return 0;
}
