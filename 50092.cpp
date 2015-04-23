////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-16 21:06:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5009
////Problem Title: 
////Run result: Accept
////Run time:718MS
////Run memory:888KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sun 14 Sep 2014 03:14:15 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;

int n,a[50010],b[50010],q[300],len;
int dp[50010];
bool vis[50010];

int main(){
     while(scanf("%d",&n) != EOF){
         for(int i = 1; i <= n; ++i){
             scanf("%d",a + i);
             b[i] = a[i];
         }
         sort(b + 1,b + n + 1);
         int size = unique(b + 1,b + n + 1) - b - 1;
         for(int i = 1; i <= n; ++i)
             a[i] = lower_bound(b + 1,b + size + 1,a[i]) - b;
         int tn = n;
         n = 1;
         for(int i = 2; i <= tn; ++i) if(a[i] != a[i - 1]){
            a[++n] = a[i];
         }
         int ra = sqrt(1.0 * n);
         if(ra * ra != n) ++ra;
         memset(dp,INF,sizeof(dp));
         dp[0] = 0;
         dp[n] = n;
            for(int i = 0; i < n; ++i){
             len = 0;
             if(dp[i] > dp[i + 1]) continue;
             for(int j = i + 1; j <= n; ++j){
                 if(vis[a[j]] == 0){
                    vis[a[j]] = 1;
                    q[++len] = a[j];
                 }
                 if(dp[i] + len * len >= dp[n]) break;
                 dp[j] = min(dp[j],dp[i] + len * len);
             }
             for(int i = 1; i <= len; ++i){
                vis[q[i]] = 0;
             }
         }
         printf("%d\n",dp[n]);
     }
     return 0;
}