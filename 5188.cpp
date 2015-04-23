////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-15 10:58:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5188
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:2064KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
typedef long long LL;
int n , w;
struct opt {
    int t , v , l; 
    bool operator < (const opt& R) const {
        return l < R.l;
    }
}a[30];
LL f[2][3000005];

void work() {
    int i , j; LL sum = 0;
    for (i = 0 ; i < n ; ++ i) {
        scanf("%d%d%d",&a[i].t , &a[i].v , &a[i].l);
        sum += a[i].v , a[i].l -= a[i].t;
    }
    if (sum < w) {
        puts("zhx is naive!");
        return;
    }
    sort(a , a + n);
    int T = 0;
    int cur = 0 , nxt = 1;
    f[0][0] = 0;
    for (i = 0 ; i < n ; ++ i) {
        int nxtT = max(T , a[i].l) + a[i].t;
        memcpy(f[nxt] , f[cur] , T + 1 << 3);        
        for (j = T + 1 ; j <= nxtT ; ++ j) f[nxt][j] = 0;
        for (j = 0 ; j <= T ; ++ j) {
            int W = max(j , a[i].l) + a[i].t;
            f[nxt][W] = max(f[nxt][W] , f[cur][j] + a[i].v);
        }
        swap(nxt , cur) , T = nxtT;
    }
    for (i = 0 ; i <= T ; ++ i)
        if (f[cur][i] >= w)
            break;
    if (i <= T)
        printf("%d\n" , i);
    else
        puts("zhx is naive!");
}

int main() {
    while (~scanf("%d%d",&n,&w))
        work();
    return 0;
}