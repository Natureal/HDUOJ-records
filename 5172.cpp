////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-07 23:12:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5172
////Problem Title: 
////Run result: Accept
////Run time:2168MS
////Run memory:36400KB
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
#define REV(i,n) for(int i=(n-1);i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 1000010;

int n,m;
int val[MAXN];
int ans[MAXN];
int tmin[MAXN];
int L,R,A,C;

struct edge{
    int l,r,id;
}e[MAXN];

inline int Read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

bool cmp(edge a,edge b){
	if(a.r == b.r)
        return a.l < b.l;
    return a.r < b.r;
}

struct SMT{
    int tmin[MAXN << 2];
    void clear(){
        memset(tmin,0,sizeof(tmin));
    }
    void Update(int p,int l,int r){
        if(l == r){
            tmin[p] = C;
            return;
        }
        int mid = getmid(l,r);
        if(val[C] <= mid) Update(p << 1,l,mid);
        else Update(p << 1|1,mid + 1,r);
        tmin[p] = min(tmin[p << 1],tmin[p << 1|1]);
    }
    int Query(int p,int l,int r){
        if(1 <= l && r <= R)
            return tmin[p];
        int mid = getmid(l,r);
        int res = INF;
        if(1 <= mid) res = min(res,Query(p << 1,l,mid));
        if(R > mid) res = min(res,Query(p << 1|1,mid + 1,r));
        return res;
    }
}smt;

int main(){
    while(scanf("%d%d",&n,&m) != EOF){
        smt.clear();
        FOR(i,1,n) val[i] = Read();
        FOR(i,1,m){
			e[i].l = Read();
			e[i].r = Read();
            e[i].id = i;
        }
        sort(e + 1,e + m + 1,cmp);
        C = 1;
        FOR(i,1,m){
            for(; C <= e[i].r; ++C)
                smt.Update(1,1,n);
            R = e[i].r - e[i].l + 1;
            int res = smt.Query(1,1,n);
            if(res == e[i].l) ans[e[i].id] = 1;
            else ans[e[i].id] = 0;
        }
        FOR(i,1,m){
            if(ans[i]) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
