////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-18 12:05:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5159
////Problem Title: 
////Run result: Accept
////Run time:1185MS
////Run memory:1948KB
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
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int T,a,b;
double sum[100010];

void Pre(){
    sum[0] = 0.0;
    for(int i = 1; i <= 100000; ++i)
        sum[i] = sum[i - 1] + (double)i;
}

int main(){
    Pre();
    scanf("%d",&T);
    for(int tt = 1; tt <= T; ++tt){
        scanf("%d%d",&a,&b);
        double p = 1.0 - pow((double)a - 1.0,b) / pow((double)a,b);
        printf("Case #%d: %.3f\n",tt,sum[a] * p);
    }
    return 0;
}