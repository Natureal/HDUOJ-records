////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-15 11:52:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5186
////Problem Title: 
////Run result: Accept
////Run time:249MS
////Run memory:1628KB
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

int tlen,n,B;
char ts[300];
int s[300],ans[300];

inline int Trans(char cur){
    if(cur >= '0' && cur <= '9') return cur - '0';
    return cur - 'a' + 10;
}

int main(){
    while(scanf("%d%d",&n,&B) != EOF){
        int max_len = 0;
        MEM(ans,0);
        REP(i,n){
            scanf("%s",ts);
            tlen = strlen(ts);
            max_len = max(max_len,tlen);
            for(int j = 0; j < tlen; ++j) s[tlen - 1 - j] = Trans(ts[j]);
            if(i == 1) for(int j = 0; j < tlen; ++j) ans[j] = s[j];
            else for(int j = 0; j < tlen; ++j) ans[j] = (ans[j] + s[j]) % B;
        }
        int i;
        for(i = max_len - 1; i >= 0; --i) if(ans[i] != 0) break;
        if(i < 0) printf("0");
        for(; i >= 0; --i){
            if(ans[i] >= 10) printf("%c",'a' + ans[i] - 10);
            else printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}