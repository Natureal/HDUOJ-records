////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-13 23:45:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2062
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:244KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 2062.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Mon 13 Oct 2014 09:01:48 PM CST
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
typedef unsigned long long ull;
typedef long long ll;
const int INF = 1 << 30;

ll A[30][30],sum[30][30];
ll n,m;

int main(){
    sum[0][0] = 1;
    for(ll i = 1; i <= 20; ++i){
        A[i][0] = 1;
        sum[i][0] = 1;
        for(ll j = 1; j <= 20; ++j){
            A[i][j] = A[i][j - 1] * (i - j + 1);
            sum[i][j] = sum[i][j - 1] + A[i][j];
        }
    }
	while(scanf("%I64d%I64d",&n,&m) != EOF){
        if(n == 1){
            printf("1\n");
            continue;
        }
        ll k,c = n - 1;
        int vis[30];
        memset(vis,0,sizeof(vis));
        while(m > 0){
            k = (m + sum[c][c] - 1) / sum[c][c];
            m -= (k - 1) * sum[c][c];
            m --;
            int cnt = 0;
            for(int i = 1; i <= n; ++i){
                if(!vis[i]) ++cnt;
                if(cnt >= k){
                    k = i;
                    vis[i] = 1;
                    break;
                }
            }
            if(c < n - 1) printf(" ");
            printf("%I64d",k);
            --c;
        }
        puts("");
    }
	return 0;
}

