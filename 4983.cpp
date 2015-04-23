////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-04 13:11:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4983
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <stack>
#include <set>
#include <map>
#include <limits>
using namespace std;
#define clr(a, b) memset(a, b, sizeof(a))
#define REP(i, n) for (i = 0; i < (int)(n); ++i)
#define FOR(i, n) for (i = 1; i <= (int)(n); ++i)
#define LIN(i, u) for (i = head[u]; ~i; i = nxt[i])
#define MP make_pair
#define PB push_back
#define MAX(a, b, c) max(a, max(b, c))
#define MIN(a, b, c) min(a, min(b, c))
#define all(x) (x).begin(), (x).end()
#define ls(i) (i << 1)
#define rs(i) (i << 1 | 1)
#define pi (atan(1.0) * 4)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//}

const int MOD = 1000000007;

int n, k;

int euler(int n) {
    int ret = n;
    for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
        ret = ret / i * (i - 1);
        while (n % i == 0) n /= i;
    }
    if (n > 1) ret = ret / n * (n - 1);
    return ret;
}

ll cal() {
    if (n == 1) return 1;
    if (k >= 3) return 0;
    if (k == 2) return 1;

//    printf("%d\n", euler(2));

    ll ans = 0;
    for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
        ll sum = (ll)euler(n / i) * euler(i);
        if (i * i != n) sum *= 2;
        ans = (ans + sum) % MOD;
    }
    return ans;
}

int main() {
//    freopen("in", "r", stdin);
    while (~scanf("%d%d", &n, &k)) {
        printf("%I64d\n", cal());
    }
    return 0;
}