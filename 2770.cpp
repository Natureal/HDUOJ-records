////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-08-29 16:47:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2770
////Problem Title: 
////Run result: Accept
////Run time:3031MS
////Run memory:16768KB
//////////////////System Comment End//////////////////
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const long long inf = (long long) 1 << 50;
struct node {
    long long k, ret;
}q[30000];
long long head, rear;
long long T, n, d, h[105], cnt, st[30000], dp[105][30000];

void add(long long k, long long ret) {
    while (head <= rear && ret <= q[rear].ret) rear -= 1;
    rear += 1;
    q[rear].k = k;
    q[rear].ret = ret;
}

long long get(int k) {
    while (head <= rear && st[q[head].k] + d < st[k]) head += 1;
    if (head > rear) return inf;
    else return q[head].ret;
}

int main(int argc, char** argv) {

    cin >> T;
    while (T--) {
        cin >> n >> d;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> h[i];
            for (long long s = -n; s <= n; s++)
                st[++cnt] = h[i] + d * s;
        }
        sort(st + 1, st + cnt + 1);
        long long c = cnt;
        cnt = 1;
        for (int i = 2; i <= c; i++) {
            if (st[i] != st[cnt]) st[++cnt] = st[i];
        }
        for (int i = 1; i <= cnt; i++) {
            if (st[i] == h[1]) dp[1][i] = 0;
            else dp[1][i] = inf;
        }
        for (int i = 2; i <= n; i++) {
            head = 1;
            rear = 0;
            c = 1;
            for (int j = 1; j <= cnt; j++) {
                while (c <= cnt && st[c] - d <= st[j]) {
                    add(c, dp[i - 1][c]);
                    c += 1;
                }
                dp[i][j] = get(j) + ((st[j] > h[i]) ? (st[j] - h[i]) : (h[i] - st[j]));
            }
        }
        long long ans;
        for (int i = 1; i <= cnt; i++) {
            if (st[i] == h[n]) ans = dp[n][i];
        }
        if (ans >= inf) cout << "impossible" << endl;
        else cout << ans << endl;
    }

    return (EXIT_SUCCESS);
}
