////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-04 15:01:09
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3333
////Problem Title: 
////Run result: Accept
////Run time:812MS
////Run memory:5604KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
#define INF 0x73737373
#define EPS 1e-8
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
#define MAXN 55555
__int64 sum[MAXN<<2], A[MAXN], ans[MAXN<<2];
map <__int64, int> hash;
struct Query_Node
{
    int l, r, index;
    friend bool operator < (Query_Node a, Query_Node b)
    {
        return a.r < b.r;
    }
}q[MAXN<<2];
void push_up(int rt)
{
    sum[rt] = sum[rt<<1|1] + sum[rt<<1];
}
void update(int l, int r, int rt, int p, __int64 val)
{
    if(l == r)
    {
        sum[rt] += val;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(lson, p, val);
    else update(rson, p, val);
    push_up(rt);
}
__int64 query(int l, int r, int rt, int L, int R)
{
    if(L <= l && R >= r)
        return sum[rt];
    int m = (l + r) >> 1;
    __int64 ret = 0;
    if(L <= m) ret += query(lson, L, R);
    if(R > m) ret += query(rson, L, R);
    return ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        hash.clear();
        memset(sum, 0, sizeof(sum));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%I64d", &A[i]);
        scanf("%d", &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &q[i].l, &q[i].r);
            q[i].index = i;
        }
        sort(q, q + m);
        int pos = 1;
        for(int i = 0; i < m; i++)
        {
            for(;pos <= n && pos <= q[i].r; pos++)
            {
                if(hash[A[pos]]) update(1, n, 1, hash[A[pos]], -A[pos]);
                update(1, n, 1, pos, A[pos]);
                hash[A[pos]] = pos;
            }
            ans[q[i].index] = query(1, n, 1, q[i].l, q[i].r);
        }
        for(int i = 0; i < m; i++)
            printf("%I64d\n", ans[i]);
    }
    return 0;
}