////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-25 12:48:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5162
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1088KB
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
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int T,n;

struct node{
    int v,id;
}no[100];

bool cmp(node a,node b){
    return a.v > b.v;
}

int main(){
    int a,b,c;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
    REP(i,n){
        scanf("%d%d%d",&a,&b,&c);
        no[i].v = max(a,max(b,c));
        no[i].id = i;
    }
    sort(no + 1,no + n + 1,cmp);
    int ans[100];
    REP(i,n) ans[no[i].id] = i;
    printf("%d",ans[1]);
    FOR(i,2,n) printf(" %d",ans[i]);
    puts("");
    }
    return 0;
}
