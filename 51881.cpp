////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-15 11:31:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5188
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:13360KB
//////////////////System Comment End//////////////////
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
struct data{
    int t,v,l;
    data(int _t=0,int _v=0,int _l=0):t(_t),v(_v),l(_l){}
    bool operator<(const data& b)const{
        return max(max(t,l)+b.t,b.l)<max(max(b.t,b.l)+t,l);
    }
}a[33];
int dp[3000001];
int main(){
    int n,w;
    while(RII(n,w)==2){
        int sum=0;
        REP(i,n){
            RIII(a[i].t,a[i].v,a[i].l);
            sum+=a[i].v;
        }
        if(sum<w){
            puts("zhx is naive!");
            continue;
        }
        if(w==0){
            puts("0");
            continue;
        }
        sort(a,a+n);
        MS0(dp);
        int ma_pos=0;
        int ans=1e9;
        REP(i,n){
            ma_pos+=a[i].t;
            int low=max(a[i].t,a[i].l);
            ma_pos=max(ma_pos,low);
            ma_pos=min(ma_pos,ans);
            REP(j,ma_pos){
                dp[j+1]=max(dp[j],dp[j+1]);
            }
            for(int j=ma_pos;j>=low;j--){
                dp[j]=max(dp[j],dp[j-a[i].t]+a[i].v);
                dp[j]=max(dp[j],dp[j-1]);
                if(dp[j]>=w)ans=min(ans,j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}