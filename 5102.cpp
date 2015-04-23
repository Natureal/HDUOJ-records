////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-09 00:30:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5102
////Problem Title: 
////Run result: Accept
////Run time:1546MS
////Run memory:57576KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: c.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 08 Nov 2014 10:02:48 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
const int INF = 1 << 30;
const int maxn = 200010;

struct node{
    int u,v,w;
    node(int a,int b,int c) : u(a),v(b),w(c) {}
};

int T,n,k;
int first[maxn],next[maxn],ver[maxn],ecnt;
queue<node> Q;
ll ans;

void Init(){
    ans = ecnt = 0;
    memset(first,-1,sizeof(first));
    while(!Q.empty()) Q.pop();
}

void Add_edge(int u,int v){
    next[++ecnt] = first[u];
    ver[ecnt] = v;
    first[u] = ecnt;
}

void Bfs(){
    int sz = 2 * (n - 1),cnt = 0;
    while(!Q.empty()){
        node x = Q.front();
        Q.pop();
        --sz;
        if(cnt < k){
            ans += x.w;
            ++cnt;
        }
        else return;
        for(int i = first[x.u]; sz +cnt < k && i != -1; i = next[i]){
            int v = ver[i];
            if(v == x.v)
                continue;
            Q.push(node(v,x.u,x.w + 1));
            ++sz;
        }
    }
}

int main(){
    int a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        Init();
        k *= 2;
        for(int i = 1; i < n; ++i){
            scanf("%d%d",&a,&b);
            Add_edge(a,b);
            Add_edge(b,a);
            Q.push(node(a,b,1));
            Q.push(node(b,a,1));
        }
        Bfs();
        printf("%I64d\n",ans / 2);
    }
    return 0;
}
