////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 18:52:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5179
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1808KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <stdlib.h>
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
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int T,len;
char s[100];

int Solve(int pre,int p,int flag){
    if(p >= len) return pre != 0;
    int st = pre == 0 ? 0 : 1,ed;
    if(flag) ed = (pre == 0) ? 9 : pre;
    else ed = min(s[p] - '0',(p == 0) ? 9 : pre);
    int res = 0;
    for(int i = st; i <= ed; ++i) if(i == 0 || p == 0 || pre % i == 0){
        res += Solve(i,p + 1,flag || (i < s[p] - '0'));
    }
    return res;
}

int main(){
    scanf("%d",&T);
    REP(tt,T){
        char ts[100];
        int tmp,ans1,ans2;
        scanf("%d",&tmp);
        tmp--;
        len = 0;
        while(tmp){
            ts[len++] = tmp % 10 + '0';
            tmp /= 10;
        }
        for(int i = 0; i < len; ++i) s[i] = ts[len - i - 1];
        ans1 = Solve(0,0,0);
        scanf("%s",s);
        len = strlen(s);
        ans2 = Solve(0,0,0);
        printf("%d\n",ans2 - ans1);
    }
    return 0;
}