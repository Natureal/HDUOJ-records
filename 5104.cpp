////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-15 21:28:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5104
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:300KB
//////////////////System Comment End//////////////////
/*************************************************************************

    > File Name: a.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 15 Nov 2014 07:02:21 PM CST
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

int n;
int pri[10010],cnt;

int main(){
    for(int i = 2; i <= 10000; ++i){
        int m = sqrt(i * 1.0);
        int j;
        for(j = 2; j <= m; ++j){
            if(i % j == 0) break;
        }
        if(j > m) pri[++cnt] = i;
    }
    while(scanf("%d",&n) != EOF){
        int top = 0;
        for(int i = 1; i <= cnt; ++i){
            if(pri[i] >= n)
                break;
            ++top;
        }
        int ans = 0;
        for(int i = 1; i <= top; ++i){
            for(int j = i; j <= top; ++j){
                int k = n - pri[i] - pri[j];
                if(k < pri[j]) continue;
                int pos = lower_bound(pri +1,pri + cnt + 1,k) - pri;
                if(pri[pos] == k) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
