////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-11 23:37:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5064
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:16520KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <algorithm>

#define MX 3000
using namespace std;

int n, M;
int a[MX * MX];
int cnt[MX], val[MX][MX];

inline void chkmax(int &a, int b) {
    if (a < b) a = b;
}

main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    int Tc, i, j, k;
    int rlt, cur;
    
    for (scanf("%d", &Tc); Tc--; ) {
        scanf("%d%d", &n, &M);
        for (i = 1; i <= n; i++) scanf("%d", a + i);
        sort(a + 1, a + n + 1);
        
        cnt[cur = 1] = 1;
        for (i = 2; i <= n; i++) {
            if (a[i] == a[cur]) cnt[cur]++;
            else {
                a[++cur] = a[i];
                cnt[cur] = 1;
            }
        }
        n = cur;
        for (i = 1; i <= n; i++) val[i][i] = cnt[i];
        int ans = 0;
        
        for (i = 1; i <= n; i++) {
            k = i;
            rlt = val[i][i];
            chkmax(ans, rlt);
            for (j = i + 1; j <= n; j++) {
                for (; k > 0 && a[i] - a[k] <= a[j] - a[i]; k--)
                    chkmax(rlt, val[k][i] + 1);
                val[i][j] = rlt;
                chkmax(ans, rlt);
            }
        }
        
        printf("%d\n", ans);
    }
}